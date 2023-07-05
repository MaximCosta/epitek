##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## code on paper!
##

CC		= gcc
CFLAGS	= -W -Wall -Werror -Wextra -c -Iinclude/

SRC		= bsq.c \
		  bsq_work.c

OBJ		= bsq.o \
		  bsq_work.o

LIB		= lib/libmy.a

TARGET	= bsq

all: $(LIB) $(TARGET)

$(LIB):
	make -C ./lib/my

$(TARGET): $(OBJ) $(LIB)
	gcc -o $(TARGET) $(OBJ) -I./include -L./lib/ -lmy

$(OBJ): $(SRC)
	gcc -c $(SRC)


clean:
	rm -f $(OBJ)

fclean: clean
	make -C ./lib/my clean
	rm -f $(TARGET)

re: fclean all
	make -C ./lib/my fclean
