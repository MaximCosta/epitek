##
## EPITECH PROJECT, 2021
## B-CPE-110-MPL-1-1-pushswap-maxim.costa [WSL: Ubuntu]
## File description:
## Makefile
##

CC		=	gcc
FLAGS	=	-W -Wall -Wextra -Werror
SOURCE  =	src/main.c \
			src/my_getnbr.c \
			src/func.c
OBJS    =	src/main.o \
			src/my_getnbr.o \
			src/func.o

OUT = push_swap

all: $(OUT)

$(OUT): $(OBJS)
	@$(CC) -o $(OUT) $(FLAGS) $(OBJS)
	@$(call color, \x1b[32m, "Build success")

clean:
	@rm -f $(OBJS)
	@$(call color, \x1b[31m, "Remove success")

fclean: clean
	@rm -f $(OUT)
	@$(call color, \x1b[31m, "Remove All success")

re: fclean all