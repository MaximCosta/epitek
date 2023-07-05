##
## EPITECH PROJECT, 2021
## B-CPE-101-MPL-1-1-evalexpr-flavio.moreno
## File description:
## Makefile
##

######## COLORS #########

REDDARK	=	\033[31;1m
RED	=	\033[31;1m
GREEN	=	\033[32;1m
YEL	=	\033[33;1m
BLUE	=	\033[34;1m
PINK	=	\033[35;1m
CYAN	=	\033[36;1m
WHITE	=	\033[0m

#########################

BIN = 42sh

SRC = 	$(wildcard ./src/*.c) \
		$(wildcard ./src/input/*.c) \
		$(wildcard ./src/exec/*.c) \
		$(wildcard ./src/exec/builtins/*.c) \
		$(wildcard ./src/minishell_struct/*.c) \
		$(wildcard ./src/parser/command_exec/*.c) \
		$(wildcard ./src/parser/*.c) \
		$(wildcard ./src/parser/commands_split/*.c) \
		$(wildcard ./src/parser/list_commands/*.c) \
		$(wildcard ./src/parser/redirections/*.c) \
		$(wildcard ./src/utils/*.c) \
		$(wildcard ./src/env/*.c) \
		$(wildcard ./src/error/*.c) \
		$(wildcard ./tests/jobs/src/*.c) \

OBJ = 	$(SRC:.c=.o)

CFLAGS = -I./include
FLAGS = -L./lib/ -lmy -lprintf

LIBMY = lib/libmy.a
LIBPRINTF = lib/libprintf.a

all : $(LIBPRINTF) $(LIBMY) $(BIN)
	@ echo "$(GREEN)BUILD SUCCESS!$(WHITE)"

$(BIN) : $(OBJ)
	@ gcc -o $(BIN) $(OBJ) $(FLAGS)
	@ echo "$(WHITE)[$(GREEN)BUILD BIN$(WHITE)] OBJ\n\t ➜  \
	$(CYAN)BIN ./$@$(WHITE)"

$(LIBMY) :
	@ make -C lib/my --no-print-directory
	@ echo "$(WHITE)[$(GREEN)BUILD LIBMY(WHITE)] LIB\n\t ➜  \
	$(CYAN)LIB ./$@$(WHITE)"

$(LIBPRINTF) :
	@ make -C lib/printf --no-print-directory
	@ echo "$(WHITE)[$(GREEN)BUILD LIBPRINTF$(WHITE)] LIB\n\t ➜  \
	$(CYAN)LIB ./$@$(WHITE)"

%.o : %.c
	@ echo "$(WHITE)[$(GREEN)BUILD$(WHITE)]     $<$(WHITE)"
	@ gcc $(CFLAGS) -o $@ -c $<
	@ echo "[$(GREEN)√$(WHITE)]\t ➜  $(CYAN)$@$(WHITE)"

re : fclean all

clean :
	@ rm -rf $(OBJ)
	@ rm -rf *.gcno *.gcda
	@ make -C lib/my --no-print-directory clean
	@ make -C lib/printf --no-print-directory clean

fclean : clean
	@ echo "\e[1;32mCleaning ..."
	@ rm -rf $(BIN)
	@ rm -rf $(BIN_TEST)
	@ make -C lib/my --no-print-directory fclean
	@ make -C lib/printf --no-print-directory fclean

$(BIN_TEST):
	$(CC) -o $(BIN_TEST) minishell/mysh.c tests/mysh_test.c \
	-lcriterion --coverage

tests_run: $(BIN_TEST)
	@ ./$(BIN_TEST)