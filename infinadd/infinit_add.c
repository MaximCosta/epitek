/*
** EPITECH PROJECT, 2021
** main
** File description:
** no, real programmers use cat
*/

#include "include/bistro.h"
#include "include/my.h"
#include <stdlib.h>

int getter_sum(nb_info nb, int i1, int i2)
{
    int s1 = 0;
    int s2 = 0;

    if (i1 > -1)
        s1 = nb.val1[i1] - 48;
    if (i2 > -1)
        s2 = nb.val2[i2] - 48;
    return s1 + s2;
}

int getter_neg(nb_info nb, int i1, int i2, int re)
{
    int s1 = 0;
    int s2 = 0;

    if (i1 > -1)
        s1 = nb.val1[i1] - 48;
    if (i2 > -1)
        s2 = nb.val2[i2] - 48;

    return s1 - (s2 + re);
}

void sum(nb_info nb)
{
    int re = 0;
    int max = 0;
    int i1 = nb.len1;
    int i2 = nb.len2;

    for (; i1 > -1 || i2 > -1; i1--, i2--) {
        max = my_max(i1, i2) + 1;
        nb.res[max] = ASC(getter_sum(nb, i1, i2) + re);
        re = 0;
        if (nb.res[max] > 57) {
            re = 1;
            nb.res[max] -= 10;
        }
    }
    if (re > 0)
        nb.res[0] = 49;
}

void neg(nb_info nb)
{
    int re = 0;
    int max = 0;
    int i1 = nb.len1;
    int i2 = nb.len2;

    for (; i1 > -1 || i2 > -1; i1--, i2--) {
        max = my_max(i1, i2) + 1;
        nb.res[max] = ASC(getter_neg(nb, i1, i2, re));
        re = 0;
        if (nb.res[max] < 48) {
            re = 1;
            nb.res[max] += 10;
        }
    }
    if (re > 0)
        nb.res[max] -= 1;
}
