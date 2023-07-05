/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-kilyan.cotten
** File description:
** redirection.c
*/

#include "mysh.h"

static int do_output(command_exec_t *command, minishell_t *minishell)
{
    int fd = 0;

    if (!command->file_out)
        return 0;
    if (command->flag_out == 1) {
        fd = open(command->file_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    } else {
        fd = open(command->file_out, O_WRONLY | O_CREAT | O_APPEND, 0644);
    }
    if (fd == -1) {
        print_error(command->file_out);
        print_error(": Is a directory.\n");
        minishell->exit_status = 1;
        return 1;
    }
    command->fd_out = fd;
    return 0;
}

static int readdoc_print(void)
{
    if (isatty(0))
        my_printf("? ");
    return 0;
}

static int readdoc(command_exec_t *command, minishell_t *minishell)
{
    int fd[2] = {0};
    char *line = NULL;
    char *cmd = my_calloc(sizeof(char));

    pipe(fd);
    command->fd_in = fd[0] + readdoc_print();
    while ((line = mein_get_line())) {
        if (line[my_strlen(line) - 1] == '\n')
            line[my_strlen(line) - 1] = '\0';
        if (my_strcmp(line, command->file_in) == 0)
            break;
        line[my_strlen(line)] = '\n';
        cmd = string_append(cmd, line) + readdoc_print();
        free(line);
    }
    free(line);
    write(fd[1], cmd, my_strlen(cmd));
    close(fd[1]);
    free(cmd);
    return 0;
}

static int do_input(command_exec_t *command, minishell_t *minishell)
{
    if (!command->file_in)
        return 0;
    if (command->flag_in == 2)
        return readdoc(command, minishell);
    else {
        command->fd_in = open(command->file_in, O_RDONLY);
        if (command->fd_in == -1) {
            print_error(command->file_in);
            print_error(": No such file or directory.\n");
            return 1;
        }
    }
    return 0;
}

int exec_redirection(command_exec_t *command, minishell_t *minishell)
{
    int fd = 0;

    if (do_output(command, minishell))
        return 1;
    if (do_input(command, minishell))
        return 1;
    return 0;
}
