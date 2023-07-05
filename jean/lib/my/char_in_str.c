/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** char_in_str
*/

#include "my.h"

int char_in_str(char c, char *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        if (c == str[i])
            return 1;
    return 0;
}
