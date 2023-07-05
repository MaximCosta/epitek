SRC =    matrix.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra

NAME = matrix

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  $(OBJ) -o $(NAME)  -lncurses

clean:
	$(RM) $(OBJ)

fclean:    clean
	$(RM) $(NAME)

re:    fclean all
