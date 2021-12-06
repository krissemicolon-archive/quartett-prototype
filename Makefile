.POSIX:
BIN=quartett
CC=gcc
CFLAGS=-Wall
LDFLAGS=-Iinclude
SOURCES:=$(shell find src -name '*.c')

build: $(SOURCES)
	$(CC) $^ -o $(BIN) $(CFLAGS) $(LDFLAGS)

clean: $(BIN)
	rm $^

install: $(BIN)
	chmod +x $^
	cp -f $^ /usr/local/bin

remove: /usr/local/bin/$(BIN)
	rm $^

.PHONY: clean install remove
