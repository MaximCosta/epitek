##
## EPITECH PROJECT, 2021
## MyDefender - 2D Tower Defense Game
## File description:
## Makefile
##

MAKEFLAGS += --no-print-directory



BIN = raytracer

SRC_DIRS = ./core/src
SRCS := $(shell find $(SRC_DIRS) -name "*.cpp")
OBJS = $(SRCS:.cpp=.o)
CFLAGS =
CPPFLAGS = $(shell find ./core ./api -type d | awk '{printf "-I%s ", $$0}')



CC = g++

all : $(BIN)

$(BIN) : $(OBJS)
	@ $(CC) -o $(BIN) $(SRCS) $(CFLAGS) $(CPPFLAGS) -lconfig++ -g3

clean :
	@ $(RM) -rf $(OBJS)
	@ $(RM) -rf *.gcda
	@ $(RM) -rf *.gcno

fclean : clean
	@ $(RM) -rf $(BIN)

re : fclean all

docs :
	@ doxygen Doxyfile