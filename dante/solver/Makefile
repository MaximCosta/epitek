##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make
##

SRC	=	$(wildcard ./src/*.c) \
		$(wildcard ./src/struct/*.c) \
		$(wildcard ./src/env/*.c) \
		$(wildcard ./src/params/*.c) \
		$(wildcard ./src/exec/*.c) \
		$(wildcard ./src/builtins/*.c) \

SRC_OBJ	=	$(SRC:.c=.o)

SRC_NAME	=	solver

SRC_TESTS	=	$(wildcard ./tests/*.c) \
				$(wildcard ./src/*.c) \
				$(wildcard ./lib/my/*.c)

TEST_OBJ	=	$(SRC_TESTS:.c=.o)
BIN_TEST	=	unit_tests

LDFLAGS	=	-L../lib/my -lmy

CFLAGS	=	-Wall -Wextra -I./include
DEBUG	=	no

ifeq	($(DEBUG),yes)
	CFLAGS += -g3
endif

all:	$(SRC_NAME)

$(SRC_NAME):	$(SRC_OBJ)
	@ gcc -o $(SRC_NAME) $(SRC_OBJ) $(CFLAGS) $(LDFLAGS)
	@ echo "compiled src files"

clean:
	@ rm -f $(SRC_OBJ)
	@ rm -rf *.gcda
	@ rm -rf *.gcno
	@ echo "Cleaning..."

fclean:	clean
	@ rm -f $(SRC_NAME)
	@ rm -f $(TEST_OBJ)
	@ rm -f $(BIN_TEST)
	@ echo "Cleaned"

re:	fclean all

tests_run : fclean $(BIN_TEST)

$(BIN_TEST) : $(TEST_OBJ)
	@ $(CC) -o $(BIN_TEST) $(TEST_OBJ) -lcriterion --coverage -I./include
	@ ./$(BIN_TEST)

.PHONY:	all	make_lib clean fclean re tests_run