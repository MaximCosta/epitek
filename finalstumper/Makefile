##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## ..
##

BIN		=	rush3

SRC		=	final_stumper.c \
			rush.c

OBJ		=	final_stumper.o \
			rush.o

LIB		=	lib/libmy.a

all : $(LIB) $(BIN)

$(LIB) :
	 make -C ./lib/my

$(BIN) : $(OBJ) $(LIB)
	 gcc -o $(BIN) $(OBJ) -I./include -L./lib/ -lmy

$(OBJ) : $(SRC)
	 gcc -c $(SRC)

clean:
	 rm -rf $(OBJ)
	 make -C ./lib/my clean

fclean : clean
	 rm -rf $(BIN)
	 make -C ./lib/my fclean

re : fclean all
