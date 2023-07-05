/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** my getnbr
*/

#include <stdio.h>

int my_strlen(char const *str);
int is_number(char c);
int get_nbr_get_start(char const *str);
int get_stop(char const *str);
int is_number(char c);

static int get_sign(char const *str)
{
    int count = 0;
    int start = 0;

    while (str[start] == '-' || str[start] == '+') {
        if (str[start] == '-') {
            count++;
        }
        start++;
    }
    return count % 2 ? 0 : 1;
}

static int get_nbrp(char const *str, int start)
{
    int res = 0;
    int count = 1;
    int tmp;

    while (is_number(str[start])) {
        if (res * 10 < res || count > 10)
            return 0;
        res *= 10;
        tmp = res + str[start] - '0';
        if (tmp < res && tmp != 2147483647) {
            return 0;
        }
        res = tmp;
        start++;
        count++;
    }
    return res;
}

static int get_nbrn(char const *str, int start)
{
    int res = 0;
    int count = 1;
    int tmp;

    while (is_number(str[start])) {
        if (res * 10 > res || count > 10) {
            return 0;
        }
        res *= 10;
        tmp = res - str[start] + '0';
        if (tmp > res && tmp - 1 != 2147483647) {
            return 0;
        }
        res = tmp;
        start++;
        count++;
    }
    return res;
}

int my_getnbr(char const *str)
{
    int start = get_nbr_get_start(str);
    int sign = get_sign(str);

    if (!is_number(str[0]) && !(str[0] == '-' || str[0] == '+')) {
        return 0;
    }
    if (sign == 1) {
        return get_nbrp(str, start);
    } else {
        return get_nbrn(str, start);
    }
}
