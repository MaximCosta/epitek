##
## EPITECH PROJECT, 2021
## my_ls [WSL: Ubuntu]
## File description:
## Makefile
##

TARGET	= my_ls

CC		= gcc -g
CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra -g3


SRC		= $(wildcard ./src/*.c)

OBJ		= $(SRC:.c=.o)

LIB = -L ./lib/ -lmy
RM		= rm -f


all: $(TARGET)

$(TARGET): $(OBJ)
		make -C ./lib/my/
		$(CC) $(OBJ) -o $(TARGET) $(CFLAGS) $(LIB)

clean:
	make -C ./lib/my/ clean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)
	make -C ./lib/my/ fclean

re: fclean all

.PHONY: all clean fclean re
