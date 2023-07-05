##
## EPITECH PROJECT, 2023
## B-PSU-400-MPL-4-1-strace-maxim.costa
## File description:
## Makefile
##

NAME	= strace

ASM	= nasm

LD	= gcc

SRC	= $(wildcard src/*.c)

OBJ	= ${SRC:.c=.o}

CFLAGS	= -I./include -Wall -Wextra -W

LDFLAGS	= -fno-builtin

ASMFLAGS= -f elf64

.S.o:
	$(ASM) $(ASMFLAGS) $< -o $@

$(NAME): $(OBJ)
	$(LD) $(OBJ) -o $(NAME) $(LDFLAGS)

all: $(NAME)

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re
