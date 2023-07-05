##
## EPITECH PROJECT, 2021
## Lib My
## File description:
## Makefile
##

CC			= 	gcc
CFLAGS		= 	-W -Wall -Werror -Wextra -I../../include/

LIB_SRC		= 	$(wildcard *.c)

LIB_OBJ 	= 	$(LIB_SRC:.c=.o)

TARGET_LIB	= 	libmy.a

all: $(TARGET_LIB)

$(TARGET_LIB):
	@$(CC) $(CFLAGS) -c $(LIB_SRC)
	@ar src $(TARGET_LIB) $(LIB_OBJ)
	@cp $(TARGET_LIB) ../

clean:
	@rm -rf $(LIB_OBJ)

fclean: clean
	@rm -rf $(TARGET_LIB)
	@rm -rf ../$(TARGET_LIB)

re : fclean all
