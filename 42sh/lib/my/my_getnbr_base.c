/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** my getnbr
*/

#include <stdio.h>
int my_strlen(char const *str);
int is_number(char c);
int get_start(char const *str);
int get_stop(char const *str);
int is_number(char c);
int get_index(char const *str, char c);
int is_equal(char c);
int is_letter(char c);

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

static long int get_nbr(char const *str, int start, int b, char const *bas_t)
{
    long int res = 0;

    while ((is_number(str[start]) || is_letter(str[start])) && str[start]) {
        res = res * b + get_index(bas_t, str[start]);
        start++;
    }
    return res;
}

int my_getnbr_base(char const *str, char const *base_tab)
{
    int start = get_start(str);
    int sign = get_sign(str) ? 1 : -1;
    long int res;
    int base = my_strlen(base_tab);

    if (!is_number(str[0]) && !is_equal(str[0]) && !is_letter(str[0])) {
        return 0;
    }
    res = get_nbr(str, start, base, base_tab) * sign;
    if (res > 2147483647 || res < -2147483648)
        return 0;
    return res;
}
