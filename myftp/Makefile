##
## EPITECH PROJECT, 2023
## myftp [WSL: Ubuntu]
## File description:
## Makefile
##

CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -I./includes
SRC = $(shell find . -name "*.c")
OBJ = $(SRC:.c=.o)
BIN = myftp

all: myftp

myftp: $(OBJ)
	$(CC) -o $(BIN) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BIN)

re: fclean all
