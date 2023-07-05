/*
** EPITECH PROJECT, 2022
** Make_fast
** File description:
** my_strlen
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
	int i = 0;

	for(; str[i]; i++);
	return i;
}
