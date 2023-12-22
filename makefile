CC = gcc
SRCS = main.c heap.c
TARGET = hazza_malloc

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) -o $@ $^

clean:
	rm -f $(TARGET)
