##
## EPITECH PROJECT, 2021
## test bub
## File description:
## Makefile
##

CC                      =       gcc
CFLAGS          =       -W -Wall -Werror -Wextra -I../include/
#LIBFLAGS        =       -L../lib/ -lmy -llist
TESTFLAGS       =       --coverage -lcriterion

SRC_T           =       bubble.c \
						tests/test_bubble.c

TARGET_T        =       unit_test

all: $(TARGET_T)
	@./$(TARGET_T)

$(TARGET_T):
	@$(CC) $(CFLAGS) -o $(TARGET_T) $(SRC_T) $(LIBFLAGS) $(TESTFLAGS)

clean:
	@rm -rf *.gcno *.gcda

fclean: clean
	@rm -rf $(TARGET_T)

re: fclean all