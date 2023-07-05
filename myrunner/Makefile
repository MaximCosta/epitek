##
## EPITECH PROJECT, 2021
## test [WSL: Ubuntu]
## File description:
## Makefile
##

CC = gcc

AR = ar src

DOSSIER = compil_des_o

CFLAGS  = -W -Wall -Wextra -Werror -g3

CPPFLAGS = -Iinclude/

LIB = -L ./lib/ -lmy -lm

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

SRC	= $(wildcard ./src/*.c)

OBJ =  $(SRC:.c=.o)

TARGET = my_runner

.SILENT: $(OBJ)

all: $(TARGET)

$(TARGET) : $(OBJ)
	@echo "\033[1;99mCréation de la lib... [$(@)]\033[0m"
	@echo "\033[34m"
	@make -C ./lib/my/
	@echo "\033[1;93mLa création de la lib terminé !\n\033[0m"
	@echo "\033[1;99mCréation du binaire... [$(@)]\033[0m"
	@echo "\033[34m"
	@$(CC) -o $(@) $(OBJ) $(LDFLAGS) $(LIB)
	@echo "\033[1;93mLa création de l'éxécutable est terminé !\n\033[0m"
	@echo "\033[1;95mCréation du dossier...\033[0m"
	@echo "\033[34m"
	@mkdir -p $(DOSSIER)
	@echo "\033[1;96mDossier {$(DOSSIER)} créé !\n\033[0m"
	@mv -f ./src/*.o $(DOSSIER)
	@echo "\033[1;94mMooving des .o dans $(DOSSIER): OK !\n\033[0m"

fclean :
	clear
	@echo "\033[1;90mSupression de la lib\033[0m"
	@echo "\033[34m"
	@make -C ./lib/my/ fclean
	@echo "\033[1;90mSupression de $(TARGET)\033[0m"
	@echo "\033[34m"
	@$(RM) $(TARGET)
	@echo "OK\n\033[0m"
	@echo "\033[1;91mSupression du dossier {compil_des_o}\n\033[0m"
	@rm -rf $(DOSSIER)
	@echo "\033[36mDONE\n\033[0m"

re: fclean all