##
## EPITECH PROJECT, 2023
## wolfram [WSL: Ubuntu]
## File description:
## Makefile
##

NAME = wolfram

all:
	stack build --copy-bins --local-bin-path ./
	mv $(NAME)-exe $(NAME)

clean:
	stack clean

fclean: clean
	$(RM) $(NAME) stack.yaml.lock

re: fclean all