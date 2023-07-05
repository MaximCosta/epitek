/*
** EPITECH PROJECT, 2022
** tetris [WSL: Ubuntu]
** File description:
** lib3
*/

#include "../include/tetris.h"

int isnbr(char *str)
{
    if (str == NULL)
        return (0);
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    return (1);
}

int my_atoi(char *str)
{
    int nbr = 0;

    for (int i = 0; str[i] != '\0'; i++)
        nbr = nbr * 10 + str[i] - '0';
    return (nbr);
}

int my_strncmp(char *str1, char *str2, int n)
{
    for (int i = 0; i < n; i++)
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
    return (0);
}

int my_strcmp(char *str1, char *str2)
{
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
    return (0);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(1, &str[i], 1);
}
