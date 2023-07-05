##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##


SRC_DIRS = .

SRC_TEST_DIRS = ./tests

BIN_TEST = unit_test

SRCS := $(shell find $(SRC_DIRS) -name "*.c" -not -path "./tests/*" -not -path "./bonus/*")
OBJS = $(SRCS:.c=.o)

TEST_SRCS := $(shell find $(SRC_TEST_DIRS) -name "*_test.c" -not -path "./bonus/*")

CFLAGS = -g3 -W -Wall -Wextra -std=gnu17
CPPFLAGS = -I./

all: $(BIN_TEST)

$(BIN_TEST):
	$(CC) $(SRCS) $(TEST_SRCS) $(CPPFLAGS) -o unit_test --coverage -lcriterion

re : fclean all

fclean : clean
	@ $(RM) -rf $(BIN)
	@ $(RM) -rf $(BIN_TEST)

clean :
	@ $(RM) -rf $(OBJS)
	@ rm -rf $(shell find . -name "*.gcno") $(shell find . -name "*.gcda")

tests_run: fclean
	$(CC) $(SRCS) $(TEST_SRCS) $(CPPFLAGS) -o unit_test --coverage -lcriterion
	./unit_test

tests_info: tests_run
	@ gcovr --exclude tests/

tests_info_b: tests_run
	@ gcovr --exclude tests/ --branches
