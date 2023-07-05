/*
** EPITECH PROJECT, 2022
** minishell1 [WSL: Ubuntu]
** File description:
** minishell3
*/

#include "minishell.h"

void env_shw(char *env[])
{
    for (int i = 0; env[i]; i++)
        if (my_strcmp(env[i], "-1") != 0)
            my_printf("%s\n", env[i]);
}

char *env_get(char *env[], char *s1)
{
    for (int i = 0; env[i]; i++)
        if (my_strncmp(env[i], s1, my_strlen(s1)) == 0)
            return env[i] + my_strlen(s1);
    return NULL;
}

int env_set(env_t *fenv, char *s1, char *s2)
{
    int i = 0;

    if (my_isalnum(s1, 1) == 0) {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return 1;
    }
    if (my_isalnum(s1, my_strlen(s1)) == 0) {
        write(2, "setenv: Variable name must contain alphanumeric characters.\n", 60);
        return 1;
    }
    for (i = 0; fenv->env[i]; i++) {
        if (my_strncmp(fenv->env[i], s1, my_strlen(s1)) == 0) {
            free(fenv->env[i]);
            s1 = concat(s1, "=");
            s1 = concat(s1, s2);
            fenv->env[i] = my_strdup(s1);
            return 1;
        }
    }
    return env_set1(fenv, s1, s2, i);
}

int env_set1(env_t *fenv, char *s1, char *s2, int i)
{
    for (i = 0; fenv->env[i]; i++) {
        if (my_strncmp(fenv->env[i], "-1", 2) == 0) {
            free(fenv->env[i]);
            s1 = concat(s1, "=");
            s1 = concat(s1, s2);
            fenv->env[i] = my_strdup(s1);
            return 1;
        }
    }
    fenv->env = my_strdump2d(fenv->env, 1);
    s1 = concat(s1, "=");
    s1 = concat(s1, s2);
    fenv->env[i] = my_strdup(s1);
    return 1;
}

int env_del(char *env[], char *s1)
{
    s1 = concat(s1, "=");
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], s1, my_strlen(s1)) == 0) {
            free(env[i]);
            env[i] = my_strdup("-1");
            return 1;
        }
    }
    return 0;
}
