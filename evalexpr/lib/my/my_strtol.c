/*
** EPITECH PROJECT, 2021
** lib/my/my_strtol
** File description:
** don't forget to free at the end
*/

#include "my.h"

int my_strtol(char **str)
{
    int nbr = 0;

    while (ISD(**str)) {
        nbr = POW(nbr) + NUM(**str);
        (*str)++;
    }
    return nbr;
}