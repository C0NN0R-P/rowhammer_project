# Compiler
CC = gcc
CFLAGS = -Wall -O2
TARGET = perf_test
SRC = perf_test.c

# Default rule
all: check-stress-ng $(TARGET)

# Compile the C program
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Check if stress-ng is installed
check-stress-ng:
	@if ! command -v stress-ng > /dev/null; then \
		echo "stress-ng not found! Installing..."; \
		sudo apt-get update && sudo apt-get install -y stress-ng; \
	else \
		echo "stress-ng is already installed."; \
	fi

# Clean build files
clean:
	rm -f $(TARGET)
