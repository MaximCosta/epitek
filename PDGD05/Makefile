##
## EPITECH PROJECT, 2023
## B-PDG-300-MPL-3-1-PDGD05-maxim.costa [WSL: Ubuntu]
## File description:
## Makefile
##

CC = gcc
CFLAGS = -std=gnu17 -Wall -Wextra

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

all: libstring.a

libstring.a: $(OBJECTS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) libstring.a

fclean: clean
	rm -f a.out

re: fclean all
