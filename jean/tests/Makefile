##
## EPITECH PROJECT, 2021
## Pool Day10
## File description:
## Makefile
##

CC			= 	gcc
CFLAGS		= 	-W -Wall -Werror -Wextra -I../include/
LIBFLAGS	= 	-L../lib/ -lmy -llist
TESTFLAGS	=	--coverage -lcriterion

SRC_T		=	lib/*.c \
				*.c \
				../eval_expr.c \
				../parsing.c \
				../get_infin_nbr.c \
				../infin_add.c \
				../infin_sub.c \
				../infin_mul.c \
				../infin_div.c \
				../infin_mod.c \
				../op_utils.c \
				../do_op.c \
				../op_utils_bis.c \
				../error.c \
				../garbage_collector.c \

TARGET_T 	= 	unit_test.o \

all : $(TARGET_T)
	@./$(TARGET_T)

$(TARGET_T) :
	@make -C ../lib
	@$(CC) $(CFLAGS) -o $(TARGET_T) $(SRC_T) $(LIBFLAGS) $(TESTFLAGS)

clean :
	@make clean -C ../lib
	@rm -rf *.gcno *.gcda

fclean : clean
	@make fclean -C ../lib
	@rm -rf $(TARGET_T)

re : fclean all
