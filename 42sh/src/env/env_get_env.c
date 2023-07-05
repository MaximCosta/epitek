/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-kilyan.cotten
** File description:
** env_get_env.c
*/

#include "mysh.h"

char *minishell_getenv(minishell_t *minishell, char *name)
{
    env_t *env = minishell->env;

    while (env != NULL && my_strcmp(env->name, name))
        env = env->next;
    if (env == NULL)
        return 0;
    else
        return env->value;
}
