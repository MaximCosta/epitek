##
## EPITECH PROJECT, 2021
## BS_my_print_f
## File description:
## Makefile
##

CC			=	gcc
CFLAGS      =   -W -Wall -Werror -Wextra -Iincludes/

TFLAGS		=	--coverage -lcriterion -Iincludes/

LIB_SRC		=	sources/sum_numbers.c \
				sources/sum_strings_length.c \
				sources/disp_stdarg.c \
				sources/my_put_nbr.c \
				sources/my_putchar.c \
				sources/my_putstr.c

LIB_OBJ		=	sum_numbers.o \
				sum_strings_length.o \
				disp_stdarg.o \
				my_put_nbr.o \
				my_putchar.o \
				my_putstr.o

TEST_SRC	=	tests/tests_disp_stdarg.c \
				tests/tests_sum_numbers.c \
				tests/tests_sum_strings_length.c

UNI_TARGET	=	unit_test.o

TARGET_LIB	= 	libmy.a

all: $(TARGET_LIB)

$(TARGET_LIB):
	@$(CC) $(CFLAGS) -c $(LIB_SRC)
	ar src $(TARGET_LIB) $(LIB_OBJ)
	@echo "Build OK"

unit_tests:
	$(CC) $(TFLAGS) -o $(UNI_TARGET) $(LIB_SRC) $(TEST_SRC)
	@echo "Build Test"

run_tests: unit_tests
	./$(UNI_TARGET)

clean :
	@rm -rf $(LIB_OBJ)
	@rm -rf *.gcno *.gcda
	@echo "Clean .o and tests"

fclean : clean
	@rm -rf $(TARGET_LIB) $(UNI_TARGET)
	@echo "Clean all"

re : fclean all