/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** my_putnbr_strnew
*/

#include <stdlib.h>
#include "my.h"

char *my_putnbr_strnew(int nb)
{
    int len = (nb < 0) ? my_nbrlen(nb) + 2 : my_nbrlen(nb) + 1;
    char *str = malloc(sizeof(char) * len);

    for (int i = 0; i < len; i++)
        str[i] = '\0';
    my_putnbr_str(nb, str);
    return str;
}
