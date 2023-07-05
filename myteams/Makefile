##
## EPITECH PROJECT, 2023
## B-NWP-400-MPL-4-1-myteams-hades.cuisinier
## File description:
## Makefile
##

CC	=	gcc
CFLAGS	=	-Iinclude
LDFLAGS	=	-Llibs/myteams -lmyteams -luuid

ifeq ($(nolib),yes)
	LDFLAGS	=	-Llibs/myteams -luuid
endif

ifeq ($(debug),yes)
	CFLAGS	+=	-g3
endif

SRC_SERVER	=	$(wildcard src/server/*.c) \
				$(wildcard src/utils/*.c) \
				$(wildcard src/server/commands/*.c) \
				$(wildcard src/server/struct/*.c) \
				$(wildcard src/server/loop/*.c) \
				$(wildcard src/server/users/*.c)
BIN_SERVER	=	myteams_server
OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

SRC_CLIENT	=	$(wildcard src/client/*.c) \
				$(wildcard src/client/struct/*.c) \
				$(wildcard src/client/loop/*.c) \
				$(wildcard src/client/response/*.c) \
				$(wildcard src/utils/*.c)
BIN_CLIENT	=	myteams_cli
OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)

all:	server client

server:	$(OBJ_SERVER)
	$(CC) -o $(BIN_SERVER) $(OBJ_SERVER) $(LDFLAGS)

client:	$(OBJ_CLIENT)
	$(CC) -o $(BIN_CLIENT) $(OBJ_CLIENT) $(LDFLAGS)

clean:
	rm -f $(OBJ_SERVER)
	rm -f $(OBJ_CLIENT)

fclean:	clean
	rm -f $(BIN_SERVER)
	rm -f $(BIN_CLIENT)

re:	fclean all

.PHONY:	all server client clean fclean re
