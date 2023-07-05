/*
** EPITECH PROJECT, 2021
** bistro-matic
** File description:
** infin_mod
*/

#include <stdlib.h>
#include "bistromatic.h"

static char *calculate_mod(calc cal, opbase_t opbase)
{
    int nb_zero = cal.len1 - cal.len2;
    char *mod = NULL;
    char *before = NULL;
    char *next = cal.nb1;

    if (my_strcmp_base(cal.nb1, cal.nb2, opbase.base) < 0)
        nb_zero--;
    mod = append_zero(cal.nb2, nb_zero, opbase);
    do {
        before = next;
        next = do_sub(next, mod, opbase);
    } while (*next != opbase.ops[OP_NEG] &&
        my_strcmp_base(mod, zero(opbase), opbase.base) != 0);
    cal.nb1 = before;
    cal.len1 = my_strlen(before);
    return (nb_zero <= 0) ? before : calculate_mod(cal, opbase);
}

char *infin_mod(char *nb1, char *nb2, int neg, opbase_t opbase)
{
    calc cal;

    if (*nb2 == opbase.base[0])
        exit(my_putstr_err(ERROR_MSG, EXIT_OPS));
    cal.nb1 = nb1;
    cal.nb2 = nb2;
    cal.len1 = my_strlen(nb1);
    cal.len2 = my_strlen(nb2);
    if (neg == 1)
        return do_sub(zero(opbase), calculate_mod(cal, opbase), opbase);
    return calculate_mod(cal, opbase);
}
