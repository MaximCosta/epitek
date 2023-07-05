/*
** EPITECH PROJECT, 2021
** str_utils
** File description:
** str_utils.c
*/
#include "../../include/common.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char tmp;

    while (str[i])
        i++;
    i--;
    while (i > j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i--;
        j++;
    }
    return str;
}
