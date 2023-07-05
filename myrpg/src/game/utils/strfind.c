/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-guillaume.kucia
** File description:
** strfind.c
*/

#include "../../../include/game/rpg.h"

int charnfind(char *str, char find)
{
    int result = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == find)
            result++;
    return result;
}

int strnfind(char *str, char *find)
{
    int result = 0;
    char *copy = my_strdup(str);

    for (; copy[0]; copy++)
        if (equal(copy, find))
            result++;
    return result;
}

bool strfind(char *str, char *find)
{
    char *copy = my_strdup(str);
    int size = my_strlen(find);

    for (; copy[0]; copy++)
        if (nequal(copy, find, size))
            return true;
    return false;
}

bool charfind(char *str, char find)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == find)
            return true;
    return false;
}
