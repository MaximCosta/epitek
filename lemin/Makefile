##
## EPITECH PROJECT, 2021
## MAKEFILE 101pong
## File description:
## MAKEFILE DE Création d'exécutable
##

CC = gcc

TARGET = lem_in

CFLAGS = -g3 -Wno-unused -Werror -Wextra -Wall

CPPFLAGS = -I./include

SRC = 	$(wildcard src/*.c) \
		$(wildcard src/parsing/*.c) \
		$(wildcard src/dijkstra/*.c) \
		$(wildcard src/lib/*.c) \

OBJ = $(SRC:.c=.o)

.SILENT: $(OBJ)

all : $(TARGET)

$(TARGET) : $(OBJ)
	@$(CC) -o $(TARGET) $(OBJ) $(CFLAGS)
	@mkdir -p ./compiled
	@mv $(OBJ) ./compiled

clean :
	@$(RM) -rf ./compiled/

fclean : clean
	@$(RM) $(TARGET)


re : fclean all
