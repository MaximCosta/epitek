##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC			= 	gcc
CFLAGS		= 	-W -Wall -Werror -Wextra -c -Iinclude/

SRC 		=	main.c \
				eval_expr.c \
				parsing.c \
				get_infin_nbr.c \
				infin_add.c \
				infin_sub.c \
				infin_mul.c \
				infin_div.c \
				infin_mod.c \
				op_utils.c \
				do_op.c \
				op_utils_bis.c \
				error.c \
				garbage_collector.c \

OBJ 		= 	main.o \
				eval_expr.o \
				parsing.o \
				get_infin_nbr.o \
				infin_add.o \
				infin_sub.o \
				infin_mul.o \
				infin_div.o \
				infin_mod.o \
				op_utils.o \
				do_op.o \
				op_utils_bis.o \
				error.o \
				garbage_collector.o \

TARGET		= 	calc \

all: $(TARGET)

$(TARGET): 	$(OBJ)
	@make -C lib/
	@$(CC) -o $(TARGET) $(OBJ) -Llib/ -lmy -llist
	@echo "Build OK"

tests_run:
	@make -C tests/
	@echo "Tests run"

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
