##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC			= 	gcc

CFLAGS		= 	-W -Wall -Werror -Wextra -c -Iinclude/

SRC 		=	main.c \

OBJ 		= 	main.o \

TARGET		= 	calc \

all: $(TARGET)

$(TARGET): 	$(OBJ)
	@make -C lib/
	@$(CC) -o $(TARGET) $(OBJ) -Llib/ -lmy -llist
	@echo "Build OK"

clean :
	@make clean -C lib/
	@make clean -C tests/
	@rm -rf $(OBJ)
	@echo "Clean OK"

fclean : clean
	@make fclean -C lib/
	@make fclean -C tests/
	@rm -rf $(TARGET)
	@echo "Fclean OK"

re : fclean all
