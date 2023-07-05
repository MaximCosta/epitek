/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-kilyan.cotten
** File description:
** unsetenv.c
*/

#include "mysh.h"

int minishell_unsetenv(minishell_t *minishell, char **split)
{
    if (!split[1])
        fprintf(stderr, "unsetenv: Too few arguments.\n");
    else {
        for (int i = 1; split[i]; i++)
            minishell_env_unenv(minishell, split[i]);
    }
    return 1;
}
