/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-kilyan.cotten
** File description:
** env_print.c
*/

#include "mysh.h"

void minishell_env_print(minishell_t *minishell)
{
    env_t *tmp = minishell->env;

    while (tmp) {
        my_printf("%s=%s\n", tmp->name, tmp->value);
        tmp = tmp->next;
    }
}
