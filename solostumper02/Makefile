##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## you're a bad developer
##

CC	= gcc
CFLAG	= -W -Wall -Werror -Wextra

SRC	= anagram.c
OBJ	= anagram

TARGET	= anagram

all: $(TARGET)

$(TARGET):
	$(CC) -o $(TARGET) $(SRC) $(CFLAG)

clean:
	echo "nothing to clean"

fclean:
	rm -f $(TARGET)

re: fclean all
