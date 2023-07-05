##
## EPITECH PROJECT, 2023
## tekspice [WSL: Ubuntu]
## File description:
## Makefile
##
# Makefile for the tekspice project

CC		= g++
RM		= rm -rf
NAME	=	nanotekspice
SRC		= 	$(find . -name "*.cpp")
OBJ		=	$(SRC:.cpp=.o)
CXXFLAGS	+= -W -Wall -Wextra -Werror -std=c++17 -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re