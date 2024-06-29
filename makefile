CC = gcc
SRCS = main.c heap.c
TARGET = hmalloc

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) -o $@ $^

clean:
	rm -f $(TARGET)
