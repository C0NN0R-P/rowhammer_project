/* skx_rowhammer.c
 * Rowhammer kernel module using Skylake-X DRAM decoding logic
 * Performs double-sided Rowhammer attack on real memory rows
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <asm/cacheflush.h>
#include <asm/processor.h>
#include <linux/types.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Connor Pfreundschuh");
MODULE_DESCRIPTION("Rowhammer test with DRAM decoding on Skylake-X");

#define NUM_PAGES 1024
#define HAMMER_ROUNDS 10000000
#define FLIP_PATTERN 0xAA

struct dram_info {
	void *virt;
	phys_addr_t phys;
	int socket, imc, channel, dimm, rank, row, col, bank, bg;
};

#define GET_BITFIELD(v, lo, hi) (((v) >> (lo)) & ((1ULL << ((hi)-(lo)+1)) - 1))

static void decode_addr(struct dram_info *info) {
	phys_addr_t addr = info->phys;
	info->socket  = GET_BITFIELD(addr, 36, 39);
	info->imc     = GET_BITFIELD(addr, 34, 35);
	info->channel = GET_BITFIELD(addr, 32, 33);
	info->dimm    = GET_BITFIELD(addr, 30, 31);
	info->rank    = GET_BITFIELD(addr, 28, 29);
	info->bank    = GET_BITFIELD(addr, 24, 27);
	info->bg      = GET_BITFIELD(addr, 20, 23);
	info->row     = GET_BITFIELD(addr, 10, 19);
	info->col     = GET_BITFIELD(addr, 0, 9);
}

static inline void mfence_all(void) {
	asm volatile("mfence");
}

static void hammer(void *a, void *b) {
	int i, offset;
	for (i = 0; i < HAMMER_ROUNDS; i++) {
		for (offset = 0; offset < PAGE_SIZE; offset += 64) {
			volatile uint64_t *pa = (uint64_t *)(a + offset);
			volatile uint64_t *pb = (uint64_t *)(b + offset);
			*pa;
			clflush((void *)pa);
			*pb;
			clflush((void *)pb);
		}
		mfence_all();
	}
}

static void check_flips(void *victim, phys_addr_t phys, int row) {
	int i;
	bool flip_found = false;
	for (i = 0; i < PAGE_SIZE; i++) {
		unsigned char val = ((unsigned char *)victim)[i];
		if (val != FLIP_PATTERN) {
			pr_alert("[rowhammer] Bit flip at phys=0x%llx offset=%d: expected 0x%x got 0x%x\n",
				(unsigned long long)(phys + i), i, FLIP_PATTERN, val);
			flip_found = true;
		}
	}
	if (!flip_found)
		pr_info("[rowhammer] No bit flips detected in victim row %d\n", row);
}

static struct dram_info pages[NUM_PAGES];

static int __init skx_rh_init(void) {
	int i, j, k;
	pr_info("[rowhammer] Allocating and initializing %d pages with pattern 0x%x\n", NUM_PAGES, FLIP_PATTERN);

	for (i = 0; i < NUM_PAGES; i++) {
		pages[i].virt = (void *)__get_free_page(GFP_KERNEL);
		if (!pages[i].virt) {
			pr_err("[rowhammer] Failed to allocate page %d\n", i);
			return -ENOMEM;
		}
		memset(pages[i].virt, FLIP_PATTERN, PAGE_SIZE);
		pages[i].phys = virt_to_phys(pages[i].virt);
		decode_addr(&pages[i]);
	}

	for (i = 0; i < NUM_PAGES; i++) {
		for (j = 0; j < NUM_PAGES; j++) {
			if (i == j) continue;
			if (pages[i].channel != pages[j].channel ||
				pages[i].rank != pages[j].rank ||
				pages[i].bank != pages[j].bank)
				continue;

			if (abs(pages[i].row - pages[j].row) == 2) {
				int victim_row = (pages[i].row + pages[j].row) / 2;
				for (k = 0; k < NUM_PAGES; k++) {
					if (pages[k].channel == pages[i].channel &&
						pages[k].rank == pages[i].rank &&
						pages[k].bank == pages[i].bank &&
						pages[k].row == victim_row) {

						pr_info("[rowhammer] Hammering aggressor rows %d and %d (victim: %d) in bank %d channel %d\n",
							pages[i].row, pages[j].row, victim_row, pages[i].bank, pages[i].channel);
						hammer(pages[i].virt, pages[j].virt);
						check_flips(pages[k].virt, pages[k].phys, victim_row);
						goto out;
					}
				}
			}
		}
	}

out:
	return 0;
}

static void __exit skx_rh_exit(void) {
	int i;
	for (i = 0; i < NUM_PAGES; i++) {
		if (pages[i].virt)
			free_page((unsigned long)pages[i].virt);
	}
	pr_info("[rowhammer] Module unloaded\n");
}

module_init(skx_rh_init);
module_exit(skx_rh_exit);
