/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-kilyan.cotten
** File description:
** minishell_set_username.c
*/

#include "mysh.h"

void minishell_set_username(minishell_t *minishell)
{
    char *value = minishell_getenv(minishell, "SESSION_MANAGER");
    char *new = NULL;
    char local[] = "local/";
    int i = 0;
    if (!value) {
        minishell->user_name = value;
        return;
    }
    while (local[i] == value[i])
        i++;
    value += i;
    new = my_strdup(value);
    i = 0;
    while (new[i] != ':' && new[i])
        i++;
    new[i] = 0;
    minishell->user_name = new;
}
