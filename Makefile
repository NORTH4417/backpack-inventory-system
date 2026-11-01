# Source used to learn about Makefile: https://dunamismax.github.io/c-from-the-ground-up/chapters/31-makefiles.html

CC ?= cc
CFLAGS ?= -std=c99 -Wall -Wextra -pedantic -g

backpack: main.c backpack.c backpack.h structs.h
	$(CC) $(CFLAGS) -o backpack main.c backpack.c

clean:
	rm -f backpack

.PHONY: clean
