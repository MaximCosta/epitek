##
## EPITECH PROJECT, 2023
## B-PDG-300-MPL-3-1-PDGD04am-maxim.costa [WSL: Ubuntu]
## File description:
## Makefile
##

OUT		= z
CC	 	= gcc
FLAGS	= -Wall -Wextra
SOURCE	= $(wildcard *.c)
OBJ		= $(SOURCE:.c=.o)

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) -o $(OUT) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OUT)

re: fclean all
