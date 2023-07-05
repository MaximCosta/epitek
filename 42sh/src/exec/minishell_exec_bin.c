/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-kilyan.cotten
** File description:
** minishell_exec_bin.c
*/

#include "mysh.h"

int minishell_exec_test_path(minishell_t *minishell, char **split)
{
    char buffer[1024] = { 0 };

    if (minishell->path == 0)
        return 0;
    for (int i = 0; minishell->path[i]; i++) {
        my_strcpy(buffer, minishell->path[i]);
        my_strcat(buffer, "/");
        my_strcat(buffer, split[0]);
        if (is_exec(buffer)) {
            minishell_exec_bin_fork(minishell, split, buffer);
            free(split[0]);
            return 1;
        }
    }
    return 0;
}

void minishell_exec_bin_error_not_found(minishell_t *minishell, char *str)
{
    print_error(str);
    print_error(": Command not found.\n");
    minishell->exit_status = 1;
    return free(str);
}

void minishell_exec_bin_error_permission(minishell_t *minishell, char *str)
{
    print_error(str);
    print_error(": Permission denied.\n");
    minishell->exit_status = 1;
    return free(str);
}

int is_slash_in(char *s)
{
    while (*s) {
        if (*s++ == '/')
            return 1;
    }
    return 0;
}

void minishell_exec_bin(minishell_t *minishell, char **split)
{
    char buffer[1024] = {0};

    if (split[0][0] != '.' && split[0][0] != '/' &&
        minishell_exec_test_path(minishell, split))
        return;
    if (is_exec(split[0]) && is_slash_in(split[0]))
        return minishell_exec_bin_fork(minishell, split, split[0]);
    if (is_file_or_is_folder(split[0]) && is_slash_in(split[0]))
        return minishell_exec_bin_error_permission(minishell, split[0]);
    minishell_exec_bin_error_not_found(minishell, split[0]);
}
