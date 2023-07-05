##
## EPITECH PROJECT, 2021
## template
## File description:
## Makefile
##

MAKEFLAGS += --silent

all : corewar asm

corewar : common_lib
	@ echo "\n\e[32;1m✔ \e[1;35mCorewar created successfully !"
	@ $(MAKE) -C ./corewar/ --no-print-directory

corewar_graphic : common_lib
	@ echo "\n\e[32;1m✔ \e[1;35mCorewar with graphic mode created successfully !"
	@ $(MAKE) -C ./bonus/ --no-print-directory

asm : common_lib
	@ echo "\n\e[32;1m✔ \e[1;35mAsm created successfully !"
	@ $(MAKE) -C ./asm/ --no-print-directory

common_lib :
	@ echo "\n\e[32;1m✔ \e[1;35mCommon library created successfully !"
	@ $(MAKE) -C ./common/ --no-print-directory

test_asm : asm
	@ $(MAKE) -C ./asm/ test_asm --no-print-directory

re : fclean all

fclean : clean
	@ $(MAKE) -C ./asm/ fclean --no-print-directory
	@ $(MAKE) -C ./corewar/ fclean --no-print-directory
	@ $(MAKE) -C ./common/ fclean --no-print-directory

clean :
	@ $(MAKE) -C ./asm/ clean --no-print-directory
	@ $(MAKE) -C ./corewar/ clean --no-print-directory
	@ $(MAKE) -C ./common/ clean --no-print-directory

.PHONY: all clean re fclean
