/*
** EPITECH PROJECT, 2021
** bistro-matic
** File description:
** op_utils_bis
*/

#include <stdlib.h>
#include "bistromatic.h"

int is_in_base(char c, char const *base)
{
    for (int i = 0; i < my_strlen(base); i++) {
        if (c == base[i])
            return 1;
    }
    return 0;
}

int index_base(char const *base, char c)
{
    int cpt = 0;

    while (*base != c) {
        cpt++;
        base++;
    }
    return (cpt);
}

char *litlle_number(char c, opbase_t opbase)
{
    char *dest = get(malloc(sizeof(char) * 2), opbase);

    dest[0] = c;
    dest[1] = '\0';
    return dest;
}

void my_strncpy_nbr(char *dest, char const *src, int n, opbase_t opbase)
{
    if (n < 0) {
        *dest++ = opbase.base[0];
        *dest = '\0';
    } else {
        my_strncpy(dest, src, n);
        dest[n] = '\0';
    }
}

int get_sign(char **str, opbase_t opbase)
{
    char *begin = *str;
    int sign = 1;

    while (**str == opbase.ops[OP_NEG] || **str == opbase.ops[OP_PLUS]) {
        if (**str == opbase.ops[OP_NEG])
            sign = -sign;
        (*str)++;
    }
    if (**str != opbase.ops[OP_OPEN_PARENT]) {
        *str = begin;
        return 0;
    } else
        (*str)++;
    return sign;
}
