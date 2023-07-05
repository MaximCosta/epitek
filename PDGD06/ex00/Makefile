##
## EPITECH PROJECT, 2023
## B-PDG-300-MPL-3-1-PDGD06-maxim.costa [WSL: Ubuntu]
## File description:
## Makefile
##

CC = g++
CFLAGS = -std=c++20 -Wall -Wextra -Werror
EXEC = Z
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(EXEC)

re: fclean all
