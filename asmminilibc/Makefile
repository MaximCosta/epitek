##
## EPITECH PROJECT, 2023
## asmminilibc [WSL: Ubuntu]
## File description:
## Makefile
##

ASM	=	nasm
CC	=	gcc
RM	=	rm -f
ASFLAGS	=	-f elf64
NAME	=	libasm.so
T_NAME	=	lib_test
SRCS	=	$(wildcard src/*.asm)
T_SRCS	=	src/lib_tests.c
OBJS	=	$(SRCS:.asm=.o)
T_OBJS	=	$(T_SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -nostdlib -shared -fPIC $(OBJS) -o $(NAME)

test: re
	$(CC) -o main main.c
	./main

%.o : %.asm
	$(ASM) $(ASFLAGS) -o $@ $<

clean:
	$(RM) $(OBJS) $(T_OBJS) main

fclean: clean
	$(RM) $(NAME) $(T_NAME)

re: fclean all

.PHONY: all clean fclean re
