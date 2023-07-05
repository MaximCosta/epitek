##
## EPITECH PROJECT, 2021
## B-MUL-100-MPL-1-1-myscreensaver-maxim.costa [WSL: Ubuntu]
## File description:
## Makefile
##

CC = gcc

SRC = 	main.c \
		display.c \
		my_put_nbr.c \
		my_putchar.c \
		screen_1.c \
		screen_2.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -I./include/

LDFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

RM = rm -f

NAME = my_screensaver

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIB) -o $(NAME) -lm $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
