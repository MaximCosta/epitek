##
## EPITECH PROJECT, 2021
## MyDefender - 2D Tower Defense Game
## File description:
## Makefile
##

MAKEFLAGS += --silent

SRC_DIRS = ./src

BIN = my_rpg
BIN_TEST = my_rpg_test

SRCS := $(shell find $(SRC_DIRS) -name "*.c")
OBJS = $(SRCS:.c=.o)

CFLAGS = -g3
CPPFLAGS = -I./include

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

all : $(BIN)

$(BIN) : $(OBJS)
	@ $(CC) $(OBJS) -o $(BIN) $(LDFLAGS)

%.o :    %.c
	@ echo "\e[92;1m[\e[36;1m⏳ \e[92;1m] \
\e[1;32mCompiling\e[1;35m $< \e[1;32m...\e[1;0m"
	@ $(CC) -o $@ -c $< $(CFLAGS) $(CPPFLAGS)
	@ echo "    \e[32;1m✔ \e[34m\"\e[1;35m$(@)\e[34m\" \
\e[1;32mSuccessfully compiled !"
re : fclean all

fclean : clean
	@ $(RM) -rf $(BIN)

clean :
	@ $(RM) -rf $(OBJS)
	@ rm -rf $(shell find . -name "*.gcno") $(shell find . -name "*.gcda")

$(BIN_TEST):
	$(CC) -o $(BIN_TEST) bark/bark.c tests/bark_test.c -lcriterion --coverage

tests_run: $(BIN_TEST)
	@ ./$(BIN_TEST)
