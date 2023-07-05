##
## EPITECH PROJECT, 2023
## panoramix [WSL : Ubuntu]
## File description:
## Makefile
##


SRC		=	$(wildcard src/*.c)

CFLAGS	=	-Wall -Wextra -Iinclude -lpthread

OBJS	=	$(SRC:.c=.o)

NAME	=	panoramix

all:	$(NAME)

$(NAME): $(OBJS)
	gcc -g -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	@rm -rf $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all
