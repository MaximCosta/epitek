/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-kilyan.cotten
** File description:
** builtsins.c
*/

#include "mysh.h"

int minishell_builtins(minishell_t *minishell, char **split)
{
    if (!my_strcmp(*split, "exit"))
        return minishell_exit(minishell, split);
    if (!my_strcmp(*split, "env"))
        return minishell_env(minishell);
    if (!my_strcmp(*split, "cd"))
        return minishell_cd(minishell, split);
    if (!my_strcmp(*split, "setenv"))
        return minishell_setenv(minishell, split);
    if (!my_strcmp(*split, "unsetenv"))
        return minishell_unsetenv(minishell, split);
    if (!my_strcmp(*split, "which"))
        return minishell_which(minishell, split);
    if (!my_strcmp(*split, "where"))
        return minishell_where(minishell, split);
    if (!my_strcmp(*split, "echo"))
        return minishell_echo(minishell, split);
    return 0;
}
