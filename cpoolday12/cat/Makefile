##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##
SRC	=	main.c \
		../lib/my/my_putstr.c \
		../lib/my/my_putchar.c \
		../lib/my/my_strlen.c

OBJ = $(SRC:.c=.o)

NAME = cat

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
