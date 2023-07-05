/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-kilyan.cotten
** File description:
** env.c
*/

#include "mysh.h"

void print_args(char *args)
{
    for (int i = 0; args[i] != '\0'; i++) {
        if (args[i] == '\\')
            continue;
        putchar(args[i]);
    }
}

int minishell_echo(minishell_t *minishell, char **split)
{
    for (int i = 1; split[i]; i++) {
        if (i > 1)
            putchar(' ');
        print_args(split[i]);
    }
    putchar('\n');
    return 1;
}
