/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-kilyan.cotten
** File description:
** unsetenv.c
*/

#include "mysh.h"

static int test_all_letters(char *s)
{
    while (*s) {
        if (!is_letter(*s) && !is_number(*s) && !is_special(*s))
            return 0;
        s++;
    }
    return 1;
}

static int minishell_setenv_error(minishell_t *minishell, int n)
{
    minishell->exit_status = 1;
    if (n == 1)
        ERROR("setenv: Too many arguments.\n");
    if (n == 2)
        ERROR("setenv: Variable name must begin with a letter.\n");
    if (n == 3)
        ERROR("setenv: Variable name must contain alphanumeric characters.\n");
    return 1;
}

int minishell_setenv(minishell_t *minishell, char **split)
{
    if (!split[1]) {
        minishell_env_print(minishell);
        return 1;
    }
    if (split[2] && split[3])
        return minishell_setenv_error(minishell, 1);
    if ((!is_letter(split[1][0]) && !is_number(split[1][0])))
        return minishell_setenv_error(minishell, 2);
    if (!test_all_letters(split[1]))
        return minishell_setenv_error(minishell, 3);
    if (!minishell_getenv(minishell, split[1]))
        minishell_env_append(minishell, split[1], split[2] ? split[2] : "");
    else
        minishell_env_modif_value(minishell, split[1], \
                                    split[2] ? split[2] : "");
    if (!my_strcmp(split[1], "PATH"))
        minishell_set_path(minishell);
    return 1;
}
