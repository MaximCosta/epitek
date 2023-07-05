##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## if you code on paper, you're not a real programmer
##

color = /bin/echo -e "$1$2\x1b[0m"

CC	 = gcc
FLAGS	 = -W -Wall -Wextra -Werror
OBJS	= main.o
SOURCE	= main.c
OUT = info_file

all: $(OUT)

$(OUT): $(OBJS)
	make -C lib
	@$(CC) -o $(OUT) $(FLAGS) main.c -L. -lmy
	@$(call color, \x1b[32m, "Build success")

clean:
	@rm -f $(OBJS)
	make -C lib clean
	@$(call color, \x1b[31m, "Remove success")

fclean: clean
	@rm -f $(OUT)
	make -C lib fclean
	@$(call color, \x1b[31m, "Remove All success")

re: fclean all