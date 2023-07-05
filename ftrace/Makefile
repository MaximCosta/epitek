##
## EPITECH PROJECT, 2023
## B-PSU-400-MPL-4-1-ftrace-maxim.costa
## File description:
## Makefile
##

NAME	= ftrace

ASM	= nasm

LD	= gcc

SRC	= $(wildcard src/*.c)

OBJ	= ${SRC:.c=.o}

CFLAGS	= -I./include -Wall -Wextra -W -g3 -Wno-missing-braces -Wno-unused-variable

LDFLAGS	= -fno-builtin -lelf

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
