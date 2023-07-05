/*
** EPITECH PROJECT, 2022
** src/minilib
** File description:
** hello world?
*/

#include "sand.h"

int is_unique(char *str)
{
    return (
        (str[0] != str[1]) &&
        (str[0] != str[2]) &&
        (str[0] != str[3]) &&
        (str[2] != str[1]) &&
        (str[2] != str[3]) &&
        (str[1] != str[3])
    );
}

int is_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    return (1);
}

int my_exit(char *str, int code)
{
    write(2, str, strlen(str));
    exit(code);
}

int count_char(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            count++;
    return (count);
}
