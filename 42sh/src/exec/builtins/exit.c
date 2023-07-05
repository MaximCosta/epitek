/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-kilyan.cotten
** File description:
** exit.c
*/

#include "mysh.h"

static int exit_error(int n)
{
    if (n == 1)
        fprintf(stderr, "exit: Expression Syntax.\n");
    if (n == 2)
        fprintf(stderr, "exit: Badly formed number.\n");
    return 1;
}

static int exit_zero(minishell_t *minishell)
{
    minishell->exit = 0;
    minishell->exit_status = 0;
    return 1;
}

int minishell_exit(minishell_t *minishell, char **split)
{
    if (!split[1])
        return exit_zero(minishell);
    minishell->exit_status = 1;
    if (split[2])
        return exit_error(1);
    if (!is_number(split[1][0]) && split[1][0] != '-')
        return exit_error(1);
    if (!my_str_isnum(split[1]))
        return exit_error(2);
    minishell->exit_status = my_getnbr(split[1]);
    minishell->exit = 0;
    return 1;
}
