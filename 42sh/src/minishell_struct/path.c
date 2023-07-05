/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-kilyan.cotten
** File description:
** minishell_set_path.c
*/

#include "mysh.h"

static int str_start_with(char *s, char *s1)
{
    while (*s1 && *s) {
        if (*s++ != *s1++)
            return 0;
    }
    return 1;
}

static int count_path(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i]) {
        if (str[i] == ':')
            j++;
        i++;
    }
    return j + 1;
}

static int path_len(char *str)
{
    int i = 0;

    while (str[i] && str[i] != ':')
        i++;
    return i;
}

static char **split_path(char *str)
{
    char **args = malloc(sizeof(char *) * (count_path(str) + 1));
    char **tmp = args;

    while (*str) {
        if (*str == ':')
            str++;
        else {
            *args = malloc(sizeof(char) * (path_len(str) + 1));
            my_strncpy(*args, str, path_len(str));
            args[0][path_len(str)] = 0;
            args++;
            str += path_len(str);
        }
    }
    *args = NULL;
    return tmp;
}

void minishell_set_path(minishell_t *minishell)
{
    char *s = 0;
    int i = 0;
    env_t *env = minishell->env;

    while (env != NULL && my_strcmp(env->name, "PATH"))
        env = env->next;
    if (env == NULL) {
        minishell->path = NULL;
        return;
    }
    s = env->value;
    minishell->path = split_path(s);
}
