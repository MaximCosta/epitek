/*
** EPITECH PROJECT, 2021
** bistro-matic
** File description:
** op_utils
*/

#include <stdlib.h>
#include "bistromatic.h"

int my_strcmp_base(char *nb1, char *nb2, char const *base)
{
    while (*nb1 != '\0' && *nb1 == *nb2) {
        nb1++;
        nb2++;
    }
    if (*nb1 == *nb2) {
        return (0);
    } else if (index_base(base, *nb1) > index_base(base, *nb2)) {
        return (1);
    } else {
        return (-1);
    }
}

int nb_cmp(calc cal, char const *base)
{
    int step = cal.len1 - cal.len2;

    if (step != 0)
        return step;
    return my_strcmp_base(cal.nb1, cal.nb2, base);
}

int neg_numbers(char **nb1, char **nb2, opbase_t opbase)
{
    int neg = 0;

    if (**nb1 == opbase.ops[OP_NEG])
        neg += 1;
    if (**nb2 == opbase.ops[OP_NEG])
        neg += 2;
    while (**nb1 == opbase.base[0] && *(*nb1 + 1) != '\0')
        *nb1 += 1;
    while (**nb2 == opbase.base[0] && *(*nb2 + 1) != '\0')
        *nb2 += 1;
    return neg;
}

char *zero(opbase_t opbase)
{
    char *dest = get(malloc(sizeof(char) * 2), opbase);

    dest[0] = opbase.base[0];
    dest[1] = '\0';
    return dest;
}

char *append_zero(char const *str, int nb, opbase_t opbase)
{
    int size = my_strlen(str) + nb + 1;
    char *dest = NULL;
    char *begin = NULL;

    if (nb < 0)
        return zero(opbase);
    else {
        dest = get(malloc(sizeof(char) * size), opbase);
        begin = dest;
    }
    for (int i = 0; i < size; i++)
        dest[i] = '\0';
    while (*str)
        *dest++ = *str++;
    for (int i = 0; i < nb; i++)
        *dest++ = opbase.base[0];
    return begin;
}
