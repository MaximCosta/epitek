CXX = g++

CPPFLAGS = -W -Wall -Wextra -std=c++17 -I./sources/reception -I./sources/exceptions

SRC = $(shell find -name "*.cpp")

OBJ = $(SRC:.cpp=.o)

BIN = plazza

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) -o $(BIN) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(BIN)

re: fclean all
