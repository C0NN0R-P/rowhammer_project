#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/vmalloc.h>
#include <linux/mm.h>
#include <linux/highmem.h>
#include <linux/io.h>
#include <asm/cacheflush.h>
#include <asm/processor.h>

#define HAMMER_ROUNDS 100000
#define NUM_PAGES 256
#define PAGE_ORDER 0
#define FLIP_MASK 0xFF

struct dram_info {
    phys_addr_t phys;
    void *virt;
    unsigned channel;
    unsigned rank;
    unsigned bank;
    unsigned row;
    unsigned column;
};

static struct dram_info pages[NUM_PAGES];

static inline void flush(void *addr) {
    asm volatile("clflush (%0)" :: "r"(addr));
}

static inline void mfence_all(void) {
    asm volatile("mfence");
}

static void decode_physical_address(phys_addr_t addr,
                                     unsigned *channel,
                                     unsigned *rank,
                                     unsigned *bank,
                                     unsigned *row,
                                     unsigned *column) {
    *channel = (addr >> 6) & 0x1;
    *rank = (addr >> 14) & 0x1;
    *bank = ((addr >> 17) & 0x7) ^ ((addr >> 13) & 0x7);
    *row = addr >> 18;
    *column = addr & 0x3F;
}

static void hammer_addresses(volatile uint64_t *a, volatile uint64_t *b) {
    uint64_t i;
    for (i = 0; i < HAMMER_ROUNDS; i++) {
        *a;
        mfence_all();
        flush((void *)a);

        *b;
        mfence_all();
        flush((void *)b);
    }
}

static void log_bit_flips(void *virt, phys_addr_t base_phys, size_t size) {
    int i;
    for (i = 0; i < size; i++) {
        unsigned char expected = FLIP_MASK;
        unsigned char actual = ((unsigned char *)virt)[i];
        if (actual != expected) {
            unsigned channel, rank, bank, row, column;
            phys_addr_t phys = base_phys + i;
            decode_physical_address(phys, &channel, &rank, &bank, &row, &column);
            pr_alert("Bit flip at 0x%llx (offset %d): expected 0x%02x, got 0x%02x → Channel=%u Rank=%u Bank=%u Row=%u Col=%u Flip=0x%02x\n",
                (unsigned long long)phys, i, expected, actual,
                channel, rank, bank, row, column, expected ^ actual);
        }
    }
}

static int __init rowhammer_init(void) {
    int i, j;

    pr_info("Allocating %d pages\n", NUM_PAGES);
    for (i = 0; i < NUM_PAGES; i++) {
        pages[i].virt = (void *)__get_free_pages(GFP_KERNEL | GFP_DMA, PAGE_ORDER);
        if (!pages[i].virt) {
            pr_alert("Failed to allocate page %d\n", i);
            return -ENOMEM;
        }

        memset(pages[i].virt, FLIP_MASK, PAGE_SIZE);
        pages[i].phys = virt_to_phys(pages[i].virt);
        decode_physical_address(pages[i].phys,
                                &pages[i].channel,
                                &pages[i].rank,
                                &pages[i].bank,
                                &pages[i].row,
                                &pages[i].column);
    }

    pr_info("Searching for hammerable triplets...\n");

    for (i = 0; i < NUM_PAGES; i++) {
        for (j = 0; j < NUM_PAGES; j++) {
            if (i == j) continue;
            if (pages[i].channel != pages[j].channel ||
                pages[i].rank != pages[j].rank ||
                pages[i].bank != pages[j].bank)
                continue;

            int row1 = pages[i].row;
            int row2 = pages[j].row;
            if (abs(row1 - row2) == 2) {
                int victim_row = (row1 + row2) / 2;

                // Find victim
                int k;
                for (k = 0; k < NUM_PAGES; k++) {
                    if (pages[k].channel == pages[i].channel &&
                        pages[k].rank == pages[i].rank &&
                        pages[k].bank == pages[i].bank &&
                        pages[k].row == victim_row) {

                        pr_info("Hammering rows %d and %d (victim %d) in bank %u, channel %u\n",
                                row1, row2, victim_row, pages[i].bank, pages[i].channel);

                        hammer_addresses((volatile uint64_t *)pages[i].virt,
                                         (volatile uint64_t *)pages[j].virt);

                        log_bit_flips(pages[k].virt, pages[k].phys, PAGE_SIZE);
                        goto done;
                    }
                }
            }
        }
    }

done:
    return 0;
}

static void __exit rowhammer_exit(void) {
    int i;
    for (i = 0; i < NUM_PAGES; i++) {
        if (pages[i].virt)
            free_pages((unsigned long)pages[i].virt, PAGE_ORDER);
    }
    pr_info("Rowhammer Module Unloaded\n");
}

module_init(rowhammer_init);
module_exit(rowhammer_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Connor Pfreundschuh");
MODULE_DESCRIPTION("Rowhammer Module");
