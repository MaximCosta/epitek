##
##  EPITECH PROJECT, 2021
##  MakeFile
##  File description
##  Make my lib
##

CC			=	gcc
CFLAGS		=	-W -Wall -Wextra -Werror -I../include/

LIB_SRC		=	$(wildcard *.c)

LIB_OBJ		=	$(LIB_SRC:.c=.o)

TARGET_LIB	=	libmy.a

all: $(TARGET_LIB)

$(TARGET_LIB): $(LIB_OBJ)
	ar src $(TARGET_LIB) $(LIB_OBJ)
	cp libmy.a ../

clean:
	rm -rf $(LIB_OBJ)
	rm -f $(TARGET_LIB)

fclean: clean
	rm -f ../$(TARGET_LIB)

re:	fclean all