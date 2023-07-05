##
## EPITECH PROJECT, 2021
## B-CPE-101-MPL-1-1-evalexpr-flavio.moreno
## File description:
## Makefile
##

BIN = my_sokoban
BIN_TEST = my_sokoban

SRC_DIRS = ./src

SRCS := $(shell find $(SRC_DIRS) -name "*.c")
OBJS := $(patsubst %.c, %.o, $(SRCS))

SRC_TEST := $(shell find $(SRC_DIRS) -name "*.c")

LIB = libmy.a

all : $(BIN)

$(BIN): $(OBJS)
	@ gcc -g3 -o $(BIN) $(SRCS) -I./include -lncursesw $(LDFLAGS)

$(OBJS) :
	@ gcc -c -o $@ $(patsubst %.o, %.c, $@) -I./include

re : fclean all

clean :
	@ rm -rf $(OBJS)
	@ rm -rf *.gcda
	@ rm -rf *.gcno

fclean : clean
	@ rm -rf $(LIB)
	@ rm -rf $(BIN)
	@ rm -rf $(BIN_TEST)

tests_run : unit_tests
	@ ./$(BIN_TEST)

unit_tests :
	@ gcc -o $(BIN_TEST) -lcriterion --coverage -I./include \
	$(SRC_TEST) tests/*.c

infos : fclean tests_run
	@ gcovr -s . --exclude tests/

infos_branch: fclean tests_run
	@ gcovr -s . --exclude tests/ --branches

rei : fclean infos