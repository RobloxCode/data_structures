CC := gcc
CFLAGS := -Wall -Wextra -std=c17
SRC := array_list_imp.c test/test.c
TARGET := test/test

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
