##
## EPITECH PROJECT, 2021
## B-CPE-110-MPL-1-1-BSQ-maxim.costa [WSL: Ubuntu]
## File description:
## Makefile
##

CC	=	gcc
FLAGS	=	-W -Wall -Wextra -Werror

LIB_SRC		=	$(wildcard *.c)
LIB_OBJ		=	$(LIB_SRC:.c=.o)
TARGET_LIB	=	libmy.a

all: $(TARGET_LIB)

$(TARGET_LIB):
	mkdir -p ../../include
	cp *.h ../../include
	$(CC) -c $(LIB_SRC)
	ar src $(TARGET_LIB) $(LIB_OBJ)
	mv libmy.a ../

clean:
	rm -rf $(LIB_OBJ)

fclean: clean
	rm ../libmy.a

re:	fclean all
