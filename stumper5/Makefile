##
## EPITECH PROJECT, 2022
## duostumper05
## File description:
## Makefile
##

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

CPPFLAGS = -I./include

CFLAGS = -W -Wall -Wextra -Werror

NAME = tictactoe

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) 	$(OBJ) -o $(NAME) -g3

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
