/*
** EPITECH PROJECT, 2021
** bistro-matic
** File description:
** infin_div
*/

#include <stdlib.h>
#include "bistromatic.h"

static char *calc_div(calc cal, opbase_t opbase)
{
    int nb_zero = cal.len1 - cal.len2;
    char *div = NULL;
    char *fact = NULL;
    char *before = NULL;
    char *next = cal.nb1;
    char *cpt = litlle_number(opbase.base[0], opbase);

    if (my_strcmp_base(cal.nb1, cal.nb2, opbase.base) < 0) nb_zero--;
    div = append_zero(cal.nb2, nb_zero, opbase);
    fact = append_zero(litlle_number(opbase.base[1], opbase), nb_zero, opbase);
    do {
        before = next;
        next = do_sub(next, div, opbase);
        cpt = do_add(cpt, fact, opbase);
    } while (*next != opbase.ops[OP_NEG] &&
        my_strcmp_base(div, zero(opbase), opbase.base) != 0);
    cpt = do_sub(cpt, fact, opbase);
    cal.nb1 = before;
    cal.len1 = my_strlen(before);
    return (nb_zero <= 0) ? cpt : do_add(cpt, calc_div(cal, opbase), opbase);
}

char *infin_div(char *nb1, char *nb2, int neg, opbase_t opbase)
{
    calc cal;

    if (*nb2 == opbase.base[0])
        exit(my_putstr_err(ERROR_MSG, EXIT_OPS));
    cal.nb1 = nb1;
    cal.nb2 = nb2;
    cal.len1 = my_strlen(nb1);
    cal.len2 = my_strlen(nb2);
    if (neg == 1)
        return do_sub(zero(opbase), calc_div(cal, opbase), opbase);
    return calc_div(cal, opbase);
}
