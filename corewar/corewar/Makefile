##
## EPITECH PROJECT, 2021
## MyDefender - 2D Tower Defense Game
## File description:
## Makefile
##

MAKEFLAGS += --silent

SRC_DIRS = ./src

BIN = corewar

SRCS := $(shell find $(SRC_DIRS) $(BONUS_DIRS) -name "*.c")
OBJS = $(SRCS:.c=.o)

CFLAGS =
CPPFLAGS = -I./include -I../common/include/

LDFLAGS	= -L../common/
LDLIBS = -lcommons

all : $(BIN)

$(BIN) : $(OBJS)
	@ $(CC) $(OBJS) -o $(BIN) $(LDFLAGS) $(LDLIBS)

%.o :	%.c
	@ echo "\e[92;1m[\e[36;1m⏳ \e[92;1m] \
\e[1;32mCompiling\e[1;35m $< \e[1;32m...\e[1;0m"
	@ $(CC) -o $@ -c $< $(CFLAGS) $(CPPFLAGS) \
-D START_FUNC_DEF="void start_graphic_mode(corewar_t *corewar){}" \
-D START_FUNC="start_corewar(corewar);"
	@ echo "    \e[32;1m✔ \e[34m\"\e[1;35m$(@)\e[34m\" \
\e[1;32mSuccessfully compiled !"

re : fclean all

fclean : clean
	@ $(RM) -rf $(BIN)

clean :
	@ $(RM) -rf $(OBJS)
	@ $(RM) -rf *.gcda
	@ $(RM) -rf *.gcno
