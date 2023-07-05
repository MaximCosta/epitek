/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-kilyan.cotten
** File description:
** check_all_space.c
*/

#include "mysh.h"

int check_not_all_space(char *s)
{
    for (int i = 0; s[i]; i++)
        if (s[i] != ' ' && s[i] != '\t')
            return 0;
    return 1;
}