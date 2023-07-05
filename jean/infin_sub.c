/*
** EPITECH PROJECT, 2021
** bistro-matic
** File description:
** infin_sub
*/

#include <stdlib.h>
#include "my_all.h"
#include "bistromatic.h"

static char *calculate_sub(calc cal, int neg, opbase_t opbase, int size_base)
{
    int hold = 0;
    int j1 = cal.len1 - 1;
    int j2 = cal.len2 - 1;
    int res = 0;

    for (int i = cal.len_res - 1; i >= neg; i--) {
        res = (j1 >= 0) ? index_base(opbase.base, cal.nb1[j1]) : 0;
        res -= j2 >= 0 ? (index_base(opbase.base, cal.nb2[j2]) + hold) : hold;
        hold = 0;
        if (res < 0) {
            res += size_base;
            hold = 1;
        }
        cal.res[i] = opbase.base[res];
        j1--;
        j2--;
    }
    for (j2 = 0; cal.res[j2] == opbase.base[0]; j2++);
    if (neg == 1) cal.res[--j2] = opbase.ops[OP_NEG];
    return (cal.res[j2] != 0) ? cal.res + j2 : cal.res + j2 - 1;
}

char *infin_sub(char *nb1, char *nb2, opbase_t opbase)
{
    calc cal;
    int neg = 0;

    cal.nb1 = nb1;
    cal.nb2 = nb2;
    cal.len1 = my_strlen(nb1);
    cal.len2 = my_strlen(nb2);
    if (nb_cmp(cal, opbase.base) < 0) {
        my_swap(&cal.len1, &cal.len2);
        my_swap_string(&cal.nb1, &cal.nb2);
        neg = 1;
    }
    cal.len_res = cal.len1 + 1 + neg;
    cal.res = get(malloc(sizeof(char) * (cal.len_res + 1)), opbase);
    for (int i = 0; i < cal.len_res; i++)
        cal.res[i] = opbase.base[0];
    cal.res[cal.len_res] = '\0';
    return calculate_sub(cal, neg, opbase, my_strlen(opbase.base));
}
