##
## EITECH PROJECT, 2021
## MakeFile
## File description:
## Makefile
##

BIN	=	infin_add

SRC	=	main.c \
		infinit_add.c

OBJ	=	main.o \
		infinit_add.o

LIB	=	lib/libmy.a

all : $(LIB) $(BIN)

$(LIB) :
	make -C ./lib/my

$(BIN) : $(OBJ) $(LIB)
	gcc -o $(BIN) $(OBJ) -I./include -L./lib/ -lmy

$(OBJ) : $(SRC)
	gcc -c $(SRC)


clean :
	rm -rf $(OBJ)
	make -C ./lib/my clean

fclean : clean
	rm -rf $(BIN)
	make -C ./lib/my fclean

re : fclean all
