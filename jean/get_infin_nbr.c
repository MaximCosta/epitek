/*
** EPITECH PROJECT, 2021
** Bistro-matic
** File description:
** get_infin_nbr
*/

#include <stdlib.h>
#include "bistromatic.h"

static int my_strlen_nbr(char const *str, char const *base)
{
    int cpt = 0;

    while (is_in_base(*str++, base))
        cpt++;
    return cpt;
}

char *get_infin_nbr(char **src, opbase_t opbase)
{
    char *dest = NULL;
    char *begin = NULL;
    int sign = 1;
    int size;

    while (**src == opbase.ops[OP_SUB] || **src == opbase.ops[OP_PLUS])
        if (*(*src)++ == opbase.ops[OP_SUB])
            sign = -sign;
    size = my_strlen_nbr(*src, opbase.base) + 1;
    if (sign == -1)
        size++;
    dest = get(malloc(sizeof(char) * size), opbase);
    for (int i = 0; i < size; i++)
        dest[i] = '\0';
    begin = dest;
    if (sign == -1)
        *dest++ = opbase.ops[OP_NEG];
    while (is_in_base(**src, opbase.base))
        *dest++ = *(*src)++;
    return begin;
}
