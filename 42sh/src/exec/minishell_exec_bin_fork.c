/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-kilyan.cotten
** File description:
** minishell_exec_bin_fork.c
*/

#include "mysh.h"

void minishell_exec_bin_fork_signal(minishell_t *minishell, int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGSEGV)
            print_error("Segmentation fault");
        if (WTERMSIG(status) == SIGFPE)
            print_error("Floating exception");
        print_error(WCOREDUMP(status) ? " (core dumped)\n" : "\n");
        minishell->exit_status = 0;
    }
}

void minishell_exec_bin_fork(minishell_t *minishell, char **split, char *path)
{
    int status = 0;
    int w = 0;
    char **env = NULL;

    if (execve(path, split, minishell->env_save) == -1) {
        print_error(path);
        print_error(": Exec format error. Wrong Architecture.\n");
        minishell->exit_status = 1;
    }
    exit(1);
}
