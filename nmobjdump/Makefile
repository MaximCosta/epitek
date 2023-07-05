##
## EPITECH PROJECT, 2023
## nmobjdump [WSL: Ubuntu]
## File description:
## Makefile
##

CC = gcc
CFLAGS = -I./include -Wall -Wextra -Werror #-g -ggdb
NMFLAGS =
OBJDUMPFLAGS =
NM_SOURCES = $(wildcard src/nm/*.c)
OBJDUMP_SOURCES = $(wildcard src/objdump/*.c)
NM_OBJECTS = $(NM_SOURCES:.c=.o)
OBJDUMP_OBJECTS = $(OBJDUMP_SOURCES:.c=.o)

NM_OUTPUT = my_nm
OBJDUMP_OUTPUT = my_objdump

all: nm objdump

nm: $(NM_OBJECTS)
	$(CC) $(CFLAGS) $(NMFLAGS) $^ -o $(NM_OUTPUT)

objdump: $(OBJDUMP_OBJECTS)
	$(CC) $(CFLAGS) $(OBJDUMPFLAGS) $^ -o $(OBJDUMP_OUTPUT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NM_OBJECTS) $(OBJDUMP_OBJECTS)

fclean: clean
	rm -f $(NM_OUTPUT) $(OBJDUMP_OUTPUT)

re: fclean all

.PHONY: all clean fclean re
