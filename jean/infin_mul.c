/*
** EPITECH PROJECT, 2021
** Bistro-matic
** File description:
** infin_mul
*/

#include <stdlib.h>
#include "bistromatic.h"

static char *apply_mul(cal_mul mul, int len, opbase_t opbase)
{
    char *u_p = append_zero(mul.u, 2 * len, opbase);
    char *uw = do_add(mul.u, mul.w, opbase);
    char *uw_v = do_sub(uw, mul.v, opbase);
    char *uw_v_p = append_zero(uw_v, len, opbase);
    char *u_p_uw_v_p = do_add(u_p, uw_v_p, opbase);

    return do_add(u_p_uw_v_p, mul.w, opbase);
}

static char *karatsuba(calc cal, int neg, int len, opbase_t opbase)
{
    int len1 = cal.len1 - len;
    int len2 = cal.len2 - len;
    char p[len1 + 1];
    char q[len + 1];
    char r[len2 <= 0 ? 2 : len2 + 1];
    char s[len2 <= 0 ? cal.len2 + 1 : len + 1];
    cal_mul mul;

    my_strncpy_nbr(p, cal.nb1, len1, opbase);
    my_strncpy_nbr(q, cal.nb1 + len1, len, opbase);
    my_strncpy_nbr(r, cal.nb2, (len2 <= 0) ? -1 : len2, opbase);
    my_strncpy_nbr(s, (len2 < 0) ? cal.nb2 : (cal.nb2 + len2),
        (len2 <= 0) ? cal.len2 : len, opbase);
    mul.u = do_mul(p, r, opbase);
    mul.v = do_mul(do_sub(q, p, opbase), do_sub(s, r, opbase), opbase);
    mul.w = do_mul(q, s, opbase);
    if (neg == 1)
        return do_sub(zero(opbase), apply_mul(mul, len, opbase), opbase);
    return apply_mul(mul, len, opbase);
}

static char *calculate_mul(calc cal, int neg, opbase_t opbase)
{
    int nb1;
    int nb2;
    int len = (cal.len1 / 2 % 2 == 1) ? (cal.len1 / 2 + 1) : (cal.len1 / 2);
    char *res = NULL;

    if (cal.len1 < 3) {
        nb1 = my_getnbr(convert_base(cal.nb1, opbase.base,
            "0123456789", opbase));
        nb2 = my_getnbr(convert_base(cal.nb2, opbase.base,
            "0123456789", opbase));
        nb1 *= nb2;
        res = convert_base(get(my_putnbr_strnew(nb1), opbase),
            "0123456789", opbase.base, opbase);
        if (neg == 1)
            return do_sub(zero(opbase), res, opbase);
        return res;
    }
    return karatsuba(cal, neg, len, opbase);
}

char *infin_mul(char *nb1, char *nb2, int neg, opbase_t opbase)
{
    calc cal;

    cal.nb1 = nb1;
    cal.nb2 = nb2;
    cal.len1 = my_strlen(nb1);
    cal.len2 = my_strlen(nb2);
    if (cal.len1 < cal.len2) {
        my_swap(&cal.len1, &cal.len2);
        my_swap_string(&cal.nb1, &cal.nb2);
    }
    return calculate_mul(cal, neg, opbase);
}
