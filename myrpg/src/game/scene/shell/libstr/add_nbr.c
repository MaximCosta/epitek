/*
** EPITECH PROJECT, 2021
** libstr
** File description:
** add_nbr.c
*/

#include "../../../../../include/game/rpg.h"

static void my_reversestr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char tmp = 0;

    while (i < j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
}

static void my_itoaa(int nbr, char *str)
{
    int i = 0;
    int negative = nbr < 0;

    nbr = ABS(nbr);
    if (nbr == 0)
        str[i++] = '0';
    while (nbr > 0) {
        str[i++] = nbr % 10 + '0';
        nbr /= 10;
    }
    str[i++] = negative ? '-' : 0;
    my_reversestr(str);
}

void str_add_nbr(str_t *str, int nbr)
{
    char tmp[12] = {0};

    my_itoaa(nbr, tmp);
    str_add_cstr(str, tmp);
}