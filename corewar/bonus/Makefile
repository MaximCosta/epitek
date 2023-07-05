##
## EPITECH PROJECT, 2021
## MyDefender - 2D Tower Defense Game
## File description:
## Makefile
##

MAKEFLAGS += --silent

SRC_DIRS = ./src
COREWAR_DIRS = ../corewar/src

BIN = corewar

SRCS := $(shell find $(SRC_DIRS) $(COREWAR_DIRS) -name "*.c")
SRCS_CPP := $(shell find $(SRC_DIRS) $(COREWAR_DIRS) -name "*.cpp")
OBJS = $(SRCS:.c=.o) $(SRCS_CPP:.cpp=.o)

CFLAGS =
CPPFLAGS = -I./include -I../common/include/ -I../corewar/include/

LDFLAGS	= -L../common/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
LDLIBS = -lcommons

all : fclean $(BIN)

graphic : fclean $(BIN)

$(BIN) : $(OBJS)
	@ $(CXX) $(OBJS) -o $(BIN) $(LDFLAGS) $(LDLIBS)

%.o :	%.c
	@ echo "\e[92;1m[\e[36;1m⏳ \e[92;1m] \
\e[1;32mCompiling\e[1;35m $< \e[1;32m...\e[1;0m"
	@ $(CC) -o $@ -c $< $(CFLAGS) $(CPPFLAGS) -D START_FUNC_DEF="" \
-D START_FUNC="start_graphic_mode(corewar);"
	@ echo "    \e[32;1m✔ \e[34m\"\e[1;35m$(@)\e[34m\" \
\e[1;32mSuccessfully compiled !"

%.o :	%.cpp
	@ echo "\e[92;1m[\e[36;1m⏳ \e[92;1m] \
\e[1;32mCpp compiling\e[1;35m $< \e[1;32m...\e[1;0m"
	@ $(CXX) -o $@ -c $< $(CFLAGS) $(CPPFLAGS) -D START_FUNC_DEF="" \
-D START_FUNC="start_graphic_mode(corewar);"
	@ echo "    \e[32;1m✔ \e[34m\"\e[1;35m$(@)\e[34m\" \
\e[1;32mSuccessfully compiled !"

re : fclean all

fclean : clean
	@ $(RM) -rf $(BIN)

clean :
	@ $(RM) -rf $(OBJS)
	@ $(RM) -rf *.gcda
	@ $(RM) -rf *.gcno
