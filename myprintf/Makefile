##
##  EPITECH PROJECT, 2021
##  MakeFile
##  File description
##  Make my lib
##

CC			=	gcc
CFLAGS		=	-W -Wall -Wextra -Werror -Iinclude/

LIB_SRC		=	$(wildcard lib/*.c)

LIB_OBJ		=	$(LIB_SRC:.c=.o)

TARGET_LIB	=	libmy.a

all: $(TARGET_LIB)

$(TARGET_LIB): $(LIB_OBJ)
	ar src $(TARGET_LIB) $(LIB_OBJ)

clean:
	rm -rf $(LIB_OBJ)

fclean: clean
	rm -f $(TARGET_LIB)

re:	fclean all