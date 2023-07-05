/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-kilyan.cotten
** File description:
** env_init.c
*/

#include "mysh.h"

void minishell_env_append(minishell_t *minishell, char *name, char *value)
{
    env_t *env = malloc(sizeof(env_t));
    env_t *tmp = 0;

    env->name = my_strdup(name);
    env->value = my_strdup(value);
    env->next = NULL;
    if (minishell->env == NULL) {
        minishell->env = env;
    } else {
        tmp = minishell->env;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = env;
    }
    if (minishell->env_save)
        minishell_env_to_str_free(minishell->env_save);
    minishell->env_save = minishell_env_to_str(minishell);
}

void minishell_env_append_string(minishell_t *minishell, char *s)
{
    char buffer[1024] = {0};
    int i = 0;

    while (s[i++] != '=' && s[i]);
    my_strncpy(buffer, s, i - 1);
    minishell_env_append(minishell, buffer, s + i);
}

void minishell_env_free(minishell_t *minishell)
{
    env_t *tmp = minishell->env;
    env_t *next = NULL;

    while (tmp != NULL) {
        next = tmp->next;
        free(tmp->name);
        free(tmp->value);
        free(tmp);
        tmp = next;
    }
}
