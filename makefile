PREFIX = /usr/local
CC = gcc
SRCS = *.c
TARGET = $(basename $(firstword $(SRCS)))

all: $(TARGET)

$(TARGET): $(SRCS)
    $(CC) -o $@ $^

install: $(TARGET)
    cp $(TARGET) $(PREFIX)/bin

clean:
    rm -f $(TARGET)