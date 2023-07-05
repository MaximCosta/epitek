/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-kilyan.cotten
** File description:
** exec.c
*/

#include "mysh.h"

void exec_command_fd_fork(minishell_t *minishell, command_exec_t *command)
{
    if (command->fd_in != STDIN)
        dup2(command->fd_in, STDIN);
    if (command->fd_out != STDOUT)
        dup2(command->fd_out, STDOUT);
}

void exec_command_fd(minishell_t *minishell, command_exec_t *command)
{
    if (command->fd_in != STDIN && command->next)
        close(command->fd_in);
    if (command->fd_out != STDOUT)
        close(command->fd_out);
}

int exec_command(char *path, char **args, command_exec_t *command, \
                minishell_t *minishell)
{
    int pid = 0;
    int status = 0;

    if (!command->next && minishell_builtins(minishell, args))
        return 0;
    pid = fork();
    if (pid == 0) {
        exec_command_fd_fork(minishell, command);
        if (!minishell_builtins(minishell, args))
            minishell_exec_bin(minishell, args);
        exit(minishell->exit_status);
    } else {
        exec_command_fd(minishell, command);
        if (command->next)
            minishell_exec_command(command->next, minishell);
        waitpid(-1, &status, 0);
        minishell->exit_status = WEXITSTATUS(status);
        minishell_exec_bin_fork_signal(minishell, status);
        return minishell->exit_status;
    }
}

int minishell_exec_command(command_exec_t *command, minishell_t *minishell)
{
    int fd[2] = {0};

    command->arg = minishell_parser(command->command);
    if (!command->arg)
        return -1;
    if (!*command->arg)
        return -1;
    if (exec_redirection(command, minishell))
        return -1;
    if (command->next) {
        pipe(fd);
        command->next->fd_in = fd[0];
        command->fd_out = fd[1];
    }
    exec_command(*command->arg, command->arg, command, minishell);
    return 0;
}

int minishell_exec(minishell_t *minishell)
{
    command_t *tmp = minishell->commands;
    command_exec_t *command = NULL;
    int last_status = 0;
    int death = 0;

    while (tmp) {
        last_status = minishell->exit_status != 0;
        if (tmp->exec && tmp->prev && tmp->prev->value == -1)
            death = 0;
        if ((tmp->exec && (!tmp->prev || tmp->prev->value == -1 ||
            tmp->prev->value == last_status)) && !death) {
            minishell_exec_command(tmp->exec, minishell);
        } else {
            death = 1;
        }
        tmp = tmp->next;
    }
}
