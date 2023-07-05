##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC	=	gcc
FLAGS	=	-W -Wall -Wextra -Werror -I./include

LIB_SRC	=	btree_apply_infix.c \
		btree_apply_prefix.c \
		btree_apply_suffix.c \
		btree_create_node.c \
		btree_insert_data.c \
		btree_level_count.c \
		btree_search_item.c

LIB_OBJ	=	btree_apply_infix.o \
		btree_apply_prefix.o \
		btree_apply_suffix.o \
		btree_create_node.o \
		btree_insert_data.o \
		btree_level_count.o \
		btree_search_item.o

TARGET_LIB	=	libbtree.a

all: $(TARGET_LIB)

$(TARGET_LIB):
	$(CC) -c $(LIB_SRC)
	ar src $(TARGET_LIB) $(LIB_OBJ)
clean:
	rm -rf $(LIB_OBJ)

fclean: clean
	rm btree/$(TARGET_LIB)

re:	fclean all
