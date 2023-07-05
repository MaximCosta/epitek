/*
** EPITECH PROJECT, 2021
** str_utils
** File description:
** str_utils.c
*/
#include "../../include/common.h"

bool str_contains(char *str, char c)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return true;
    }
    return false;
}

bool str_contains_only_number(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}
