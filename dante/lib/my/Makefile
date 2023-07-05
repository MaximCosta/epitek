##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make
##

CC 	= gcc
FLAGS	= -W -Wall -Wextra -Werror

LIB_SRC = $(wildcard *.c)

LIB_OBJ = $(LIB_SRC:.c=.o)

TARGET_LIB = libmy.a

all: $(TARGET_LIB)

$(TARGET_LIB): $(LIB_OBJ)
	@ar src $(TARGET_LIB) $(LIB_OBJ)

clean:
	@rm  -f $(LIB_OBJ)

fclean: clean
	@rm  -f $(TARGET_LIB)

re: fclean all
