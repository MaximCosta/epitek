/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** my_getnbr_base
*/

#include "my.h"

static int i_string(char const *base, char c)
{
    int cpt = 0;

    while (*base && *base != c) {
        cpt++;
        base++;
    }
    if (!(*base))
        return (-1);
    return (cpt);
}

int get_minus_plus(char const *s, char const *b, _Bool *p, int c)
{
    if (*s == '-') {
        *p = !(*p);
        return (get_minus_plus(s + 1, b, p, c + 1));
    } else if (*s == '+') {
        return (get_minus_plus(s + 1, b, p, c + 1));
    }
    return (c);
}

int my_getnbr_base(char const *str, char const *base)
{
    _Bool pos = 1;
    int cpt = 0;
    int size_str;
    int size_base = my_strlen(base);
    int step;
    int r = 0;

    for (int i = 0; i < cpt; i++) str++;
    size_str = my_strlen(str);
    while (*str++) {
        step = i_string(base, *(str - 1));
        if (step == -1) return (0);
        cpt = my_compute_power_it(size_base, --size_str);
        if (cpt == 0 && size_str >= 0) return (0);
        step *= cpt;
        if ((r > 2147483647 - step && pos) || (r > 2147483648 - step))
            return (0);
        r += step;
    }
    return (pos ? r : -r);
}
