##
## EPITECH PROJECT, 2021
## B-CPE-101-MPL-1-1-evalexpr-flavio.moreno
## File description:
## Makefile
##

BIN = main
BIN_LIB = libprintf.a
BIN_TEST = main_test

SRC_NMAIN =	./src/printf.c \
			./src/error.c \
			./src/lib/my_putchar.c \
			./src/lib/my_strlen.c \
			./src/lib/my_putnbr_base.c \
			./src/flags/flag_purcent.c \
			./src/flags/flag_c.c \
			./src/flags/flag_i.c \
			./src/flags/flag_s.c \
			./src/flags/flag_o.c \
			./src/flags/flag_x.c \
			./src/flags/flag_xm.c \
			./src/flags/flag_b.c \
			./src/flags/flag_u.c \
			./src/flags/flag_p.c \
			./src/flags/flag_sm.c \
			./src/flags/flag_plus.c \
			./src/flags/flag_minus.c \
			./src/flags/flag_hash.c \
			./src/flags/flag_zero.c \
			./src/flags/flag_number.c \
			./src/flags_lenght/len_flag_x.c \
			./src/flags_lenght/len_flag_i.c \
			./src/flags_lenght/len_flag_u.c \
			./src/flags_lenght/len_flag_b.c \
			./src/flags_lenght/len_flag_p.c \
			./src/flags_lenght/len_flag_c.c \
			./src/flags_lenght/get_len_flags.c \
			./src/flags_lenght/len_flag_s.c \
			./src/flags_lenght/len_flag_xm.c \
			./src/flags_lenght/len_flag_sm.c \
			./src/flags_lenght/len_flag_o.c \

SRC_MAIN = 	./src/main.c

OBJ_NMAIN =	printf.o \
			error.o \
			my_putchar.o \
			my_strlen.o \
			my_putnbr_base.o \
			flag_purcent.o \
			flag_c.o \
			flag_i.o \
			flag_s.o \
			flag_o.o \
			flag_x.o \
			flag_xm.o \
			flag_b.o \
			flag_u.o \
			flag_p.o \
			flag_sm.o \
			flag_plus.o \
			flag_hash.o \
			flag_minus.o \
			flag_zero.o \
			flag_number.o \
			len_flag_x.o \
			len_flag_i.o \
			len_flag_u.o \
			len_flag_b.o \
			len_flag_p.o \
			len_flag_c.o \
			get_len_flags.o \
			len_flag_s.o \
			len_flag_xm.o \
			len_flag_sm.o \
			len_flag_o.o \


OBJ_MAIN = main.o

all : $(BIN_LIB)

$(BIN_LIB) : $(OBJ_NMAIN)
	@ ar src $(BIN_LIB) $(OBJ_NMAIN)
	@ cp $(BIN_LIB) ../

$(BIN) : $(OBJ_NMAIN) $(OBJ_MAIN) $(LIB)
	@ echo "\e[1;32mbuild bin \e[1;30m- \e[1;34m$(BIN)\e[1;0m"
	@ gcc -o $(BIN) $(OBJ_MAIN) $(OBJ_NMAIN)

$(OBJ_NMAIN) : $(SRC_NMAIN)
	@ gcc -c $(SRC_NMAIN) -I./include

$(OBJ_MAIN) : $(SRC_MAIN)
	@ echo "\e[1;32mbuild \e[1;30m- \e[1;34m$(OBJ_MAIN)";
	@ gcc -c $(SRC_MAIN) -I./include

re : fclean all

clean :
	@ rm -rf $(OBJ_MAIN) $(OBJ_NMAIN)
	@ rm -rf *.gcda
	@ rm -rf *.gcno

fclean : clean
	@ rm -rf $(BIN)
	@ rm -rf $(BIN_TEST)
	@ rm -rf $(BIN_LIB)
	@ rm -rf *.a
	@ rm -rf ../$(BIN_LIB)

tests_run : $(BIN_TEST)
	@ ./$(BIN_TEST)

infos : fclean tests_run
	@ gcovr -s . --exclude tests/

infos_branch: fclean tests_run
	@ gcovr -s . --exclude tests/ --branches

rei : fclean infos

$(BIN_TEST) : $(SRC_TEST)
	@ gcc -o $(BIN_TEST) -lcriterion --coverage -I./include \
	lib/my/*.c $(SRC_NMAIN) tests/*.c
