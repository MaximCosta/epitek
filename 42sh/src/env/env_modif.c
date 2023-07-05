/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-kilyan.cotten
** File description:
** env_modif.c
*/

#include "mysh.h"

void minishell_env_modif_value(minishell_t *minishell, char *name, char *value)
{
    env_t *tmp = minishell->env;

    while (tmp) {
        if (my_strcmp(tmp->name, name) == 0) {
            free(tmp->value);
            tmp->value = my_strdup(value);
            return;
        }
        tmp = tmp->next;
    }
    minishell_env_append(minishell, name, value);
}

static void unset_path(minishell_t *minishell)
{
    for (int i = 0; minishell->path[i]; i++)
        free(minishell->path[i]);
    minishell->path = NULL;
}

void minishell_env_unenv(minishell_t *minishell, char *name)
{
    env_t *tmp = minishell->env;
    env_t *prev = NULL;

    while (tmp && my_strcmp(tmp->name, name)) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (!my_strcmp(name, "PATH"))
        unset_path(minishell);
    if (tmp == NULL)
        return;
    if (prev == NULL)
        minishell->env = tmp->next;
    else
        prev->next = tmp->next;
    free(tmp->name);
    free(tmp->value);
    free(tmp);
}
