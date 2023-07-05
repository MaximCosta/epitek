##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## stumper02
##

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

CPPFLAGS = -I./include

CFLAGS = -W -Wall -Wextra -Werror

NAME = gameoflife

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
