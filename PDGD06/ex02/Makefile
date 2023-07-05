##
## EPITECH PROJECT, 2023
## B-PDG-300-MPL-3-1-PDGD06-maxim.costa [WSL: Ubuntu]
## File description:
## Makefile
##

CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror
NAME = RetardUnitConverter
SRC = RetardUnitConverter.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
