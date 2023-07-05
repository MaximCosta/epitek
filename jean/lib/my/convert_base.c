/*
** EPITECH PROJECT, 2021
** Pool Day08
** File description:
** convert_base
*/

#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

static int len_of_nbr(int n, int size_base)
{
    int step = n / size_base;

    if (n < 0)
        return (1 + len_of_nbr(-n, size_base));
    else if (step != 0)
        return (1 + len_of_nbr(step, size_base));
    else
        return 1;
}

static void putnbr_base_in_string(int nbr, char *str,
    char const *base, int size_base)
{
    int neg = 0;

    if (nbr < 0) {
        neg = 1;
        nbr = -nbr;
    }
    while (nbr / size_base != 0) {
        *str++ = base[nbr % size_base];
        nbr = nbr / size_base;
    }
    *str = base[nbr % size_base];
    if (neg)
        *(++str) = '-';
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to,
    opbase_t opbase)
{
    int n;
    int size_base;
    int len;
    char *str;

    if (my_strlen(nbr) < 1 || my_strlen(base_from) < 2)
        return NULL;
    else if (my_strlen(base_to) < 2)
        return NULL;
    n = my_getnbr_base(nbr, base_from);
    size_base = my_strlen(base_to);
    len = len_of_nbr(n, size_base);
    str = malloc(sizeof(char) * (len + 1));
    get(str, opbase);
    str[len] = '\0';
    putnbr_base_in_string(n, str, base_to, size_base);
    return my_revstr(str);
}
