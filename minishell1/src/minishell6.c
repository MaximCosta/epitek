/*
** EPITECH PROJECT, 2022
** minishell1 [WSL: Ubuntu]
** File description:
** minishell6
*/

#include <errno.h>
#include <sys/wait.h>
#include "minishell.h"

void fork_wait(env_t *fenv, int *exit_code, char *line)
{
    pid_t pid;
    int wstat;

    fenv->cmd = str_split(" \t", line);
    if ((*exit_code = other_command(fenv)) == -1 && (pid = fork()) == 0)
        fork_process(fenv);
    waitpid(pid, &wstat, 0);
    *exit_code = WEXITSTATUS(wstat) == 1 ? WEXITSTATUS(wstat) : *exit_code;
    bash_print(fenv);
}