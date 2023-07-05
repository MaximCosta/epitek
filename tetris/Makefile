##
## EPITECH PROJECT, 2021
## B-PSU-200-MPL-2-1-tetris-maxim.costa
## File description:
## Makefile
##

CC = gcc

NAME = tetris

SRC =   $(shell find . -name "*.c")

OBJ = $(SRC:.c=.o)

LFLAGS = -I include/

LDLIBS = -lncursesw

OPT = -Wall -Wextra -lrt -g3

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OPT) $(OBJ) -o $(NAME) $(CSFML) $(LFLAGS) $(LDLIBS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
