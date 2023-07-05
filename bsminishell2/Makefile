##
## EPITECH PROJECT, 2022
## bsminishell2 [WSL: Ubuntu]
## File description:
## Makefile
##

OBJS	= main.o
SOURCE	= main.c
OUT		= my_pipe
CC	 	= gcc
FLAGS	= -g -c

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c

clean:
	rm -f $(OBJS) $(OUT)