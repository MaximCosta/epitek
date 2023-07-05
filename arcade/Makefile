##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CXX = g++

CFLAGS = -std=c++2a -Wall -Wextra -Werror -fPIC -fno-gnu-unique -g3
CSFLAGS = -lsfml-graphics -lsfml-system -lsfml-audio
CRFLAGS = --coverage -lcriterion
CUFLAGS = -lncurses
LFLAGS = -shared

SRC = $(wildcard src/*.cpp) \
	  $(wildcard src/Core/*.cpp) \
	  $(wildcard src/MyDlLib/*.cpp) \
	  $(wildcard src/Graphics/*.cpp) \
	  $(wildcard src/Games/*.cpp)

SRC_NCURSES = $(wildcard src/Graphics/Ncurses/*.cpp)
SRC_SDL = $(wildcard src/Graphics/Sdl2/*.cpp)
SRC_SFML = $(wildcard src/Graphics/Sfml/*.cpp)

SRC_HOME = $(wildcard src/Games/Home/*.cpp)
SRC_SNAKE = $(wildcard src/Games/Snake/*.cpp)
SRC_NIBBLER = $(wildcard src/Games/Nibbler/*.cpp)

OBJ = $(SRC:.cpp=.o)

OBJ_NCURSES = $(SRC_NCURSES:.cpp=.o)
OBJ_SDL = $(SRC_SDL:.cpp=.o)
OBJ_SFML = $(SRC_SFML:.cpp=.o)

OBJ_HOME = $(SRC_HOME:.cpp=.o)
OBJ_SNAKE = $(SRC_SNAKE:.cpp=.o)
OBJ_NIBBLER = $(SRC_NIBBLER:.cpp=.o)

###################################################

BASHHOME = createHome.bash
BASHNIBBLER = createNibbler.bash
BASHSNAKE = createSnake.bash

TARGET = arcade

NCURSES_TARGET = arcade_ncurses.so
SDL_TARGET = arcade_sdl2.so
SFML_TARGET = arcade_sfml.so
HOME_TARGET = arcade_home.so
SNAKE_TARGET = arcade_snake.so
NIBBLER_TARGET = arcade_nibbler.so

UNIT_TEST = unit_test

all: core graphicals games
	./$(BASHHOME)
	./$(BASHNIBBLER)
	./$(BASHSNAKE)

###################################################

core: $(OBJ)
	@@$(CXX) -o $(TARGET) $(OBJ) $(CFLAGS) -ldl -lstdc++fs
	@echo "\033[0;34m===== Commande 'core'\t=> DONE\033[0m"

games: $(SNAKE_TARGET) $(NIBBLER_TARGET) $(HOME_TARGET)
	@echo "\033[33;32m===== Commande 'games'\t=> DONE\033[0m"

graphicals: $(NCURSES_TARGET) $(SDL_TARGET) $(SFML_TARGET)
	@echo "\033[33;33m===== Commande 'graphicals'\t=> DONE\033[0m"

###################################################

$(NCURSES_TARGET): $(OBJ_NCURSES)
	@@$(CXX) $(CFLAGS) -c $(SRC_NCURSES) -o $(OBJ_NCURSES)
	@@$(CXX) $(LFLAGS) -rdynamic -o $(NCURSES_TARGET) $(OBJ_NCURSES) $(CUFLAGS)
	@@cp $(NCURSES_TARGET) lib
	@@rm $(NCURSES_TARGET)

$(SDL_TARGET): $(OBJ_SDL)
	@@$(CXX) $(CFLAGS) -c $(SRC_SDL) -o $(OBJ_SDL)
	@@$(CXX) $(LFLAGS) -rdynamic -o $(SDL_TARGET) $(OBJ_SDL) -lSDL2 -lGL -lSDL2_ttf -lSDL2_image
	@@cp $(SDL_TARGET) lib
	@@rm $(SDL_TARGET)

$(SFML_TARGET): $(OBJ_SFML)
	@@$(CXX) $(CFLAGS) -c $(SRC_SFML) -o $(OBJ_SFML)
	@@$(CXX) $(LFLAGS) -rdynamic -o $(SFML_TARGET) $(OBJ_SFML) $(CSFLAGS)
	@@cp $(SFML_TARGET) lib
	@@rm $(SFML_TARGET)

###################################################

$(NIBBLER_TARGET): $(OBJ_NIBBLER)
	@@$(CXX) $(CFLAGS) -c $(SRC_NIBBLER) -o $(OBJ_NIBBLER)
	@@$(CXX) $(LFLAGS) -rdynamic -o $(NIBBLER_TARGET) $(OBJ_NIBBLER) $(CSFLAGS)
	@@cp $(NIBBLER_TARGET) lib
	@@rm $(NIBBLER_TARGET)

$(SNAKE_TARGET): $(OBJ_SNAKE)
	@@$(CXX) $(CFLAGS) -c $(SRC_SNAKE) -o $(OBJ_SNAKE)
	@@$(CXX) $(LFLAGS) -rdynamic -o $(SNAKE_TARGET) $(OBJ_SNAKE) $(CSFLAGS)
	@@cp $(SNAKE_TARGET) lib
	@@rm $(SNAKE_TARGET)

$(HOME_TARGET): $(OBJ_HOME)
	@@$(CXX) $(CFLAGS) -c $(SRC_HOME) -o $(OBJ_HOME)
	@@$(CXX) $(LFLAGS) -rdynamic -o $(HOME_TARGET) $(OBJ_HOME) $(CSFLAGS)
	@@cp $(HOME_TARGET) lib
	@@rm $(HOME_TARGET)

###################################################

clean:
	@@rm -rf $(OBJ)
	@@rm -rf $(OBJ_NCURSES)
	@@rm -rf $(OBJ_SDL)
	@@rm -rf $(OBJ_SFML)
	@@rm -rf $(OBJ_NIBBLER)
	@@rm -rf $(OBJ_SNAKE)
	@@rm -rf $(OBJ_HOME)
	@@rm -rf src/Games/Home/home.txt
	@@rm -rf src/Games/Nibbler/nibbler.txt
	@@rm -rf src/Games/Snake/snake.txt
	@echo "\033[33;32m===== Commande 'clean'\t=> DONE\033[0m"

fclean: clean
	@@rm -rf $(TARGET)
	@@rm -rf lib/*.so
	@@rm -rf $(UNIT_TEST)
	@echo "\033[33;32m===== Commande 'fclean'\t=> DONE\033[0m"

re: fclean all
	@echo "\033[33;32m===== Commande 're'\t=> DONE\033[0m"
