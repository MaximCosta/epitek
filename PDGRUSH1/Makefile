##
## EPITECH PROJECT, 2022
## B-PDG-300-MPL-3-1-PDGRUSH1-maxime.santos
## File description:
## Makefile
##

CC = ghc
CFLAGS =

SRC = pushswap_checker.hs
OBJ = $(SRC:.hs=.o)
OBJI = $(SRC:.hs=.hi)
BIN = pushswap_checker

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $< -o $@

%.o: %.hs
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJI)

fclean: clean
	rm -f $(BIN)

re: fclean all
