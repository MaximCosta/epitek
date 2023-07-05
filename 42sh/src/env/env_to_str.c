/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-kilyan.cotten
** File description:
** env_to_str.c
*/

#include "mysh.h"

static int env_len(env_t *env)
{
    int i = 0;

    while (env) {
        i++;
        env = env->next;
    }
    return i;
}

char **minishell_env_to_str(minishell_t *minishell)
{
    char **env = malloc(sizeof(char *) * (env_len(minishell->env) + 1));
    env_t *tmp = minishell->env;
    int i = 0;

    for (i = 0; tmp; i++) {
        env[i] = malloc(sizeof(char) * (my_strlen(tmp->name) + \
                                        my_strlen(tmp->value) + 2));
        my_strcpy(env[i], tmp->name);
        my_strcat(env[i], "=");
        my_strcat(env[i], tmp->value);
        tmp = tmp->next;
    }
    env[i] = NULL;
    return env;
}

void minishell_env_to_str_free(char **env)
{
    int i = 0;

    if (!env)
        return;
    while (env[i]) {
        free(env[i]);
        i++;
    }
    free(env);
}
