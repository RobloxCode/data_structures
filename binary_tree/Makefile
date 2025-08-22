# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c17

# Source files
SRC = b_tree_imp.c test/test.c

# Output executable (inside test/)
TARGET = test/test

# Default rule
all: $(TARGET)

# Build the executable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean up
clean:
	rm -f $(TARGET)
