/*
** EPITECH PROJECT, 2023
** B-PSU-400-MPL-4-1-ftrace-maxim.costa
** File description:
** utils
*/

#include "ftrace.h"

bool str_contains(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return true;
    return false;
}
