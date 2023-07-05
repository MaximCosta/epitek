/*
** EPITECH PROJECT, 2021
** Day08
** File description:
** Task01 - MY_STRDUP
*/

#include "../../include/common.h"

int get_calculations(char const *str, int i, int *ptr, int number)
{
    if (str[i] >= 48 && str[i] <= 57) {
        number = (number * 10) + (str[i] - 48);
        return number;
    } else if (str[i] == '-') {
        *ptr += 1;
        return number;
    }
    if (str[i] != '+')
        return number;
    return number;
}

int my_getnbr(char const *str)
{
    int i = 0;
    long int number = 0;
    int operator_logic = 0;

    while (str[i]) {
        number = get_calculations(str, i, &operator_logic, number);
        if (number > 2147483647 || number + 1 < -2147483647)
            return 0;
        i++;
    }
    if (operator_logic != 0 && operator_logic % 2 == 1)
        return number * -1;
    else
        return number;
}

long long int get_calculations_long(
    char const *str, int i, int *ptr, long long int number)
{
    if (str[i] >= 48 && str[i] <= 57) {
        number = (number * 10) + (str[i] - 48);
        return number;
    } else if (str[i] == '-') {
        *ptr += 1;
        return number;
    }
    if (str[i] != '+')
        return number;
    return number;
}

long long int my_getnbr_long(char const *str)
{
    int i = 0;
    long int number = 0;
    int operator_logic = 0;

    while (str[i]) {
        number = get_calculations_long(str, i, &operator_logic, number);
        i++;
    }
    if (operator_logic != 0 && operator_logic % 2 == 1)
        return number * -1;
    else
        return number;
}
