/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** My_revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    int cpt = 0;
    char *rev = str;

    while (*str != '\0') {
        cpt++;
        str++;
    }
    for (int i = 0; i < cpt; i++) {
        if (i < cpt / 2)
            my_swap_char(rev++, --str);
        else
            str--;
    }
    return (str);
}
