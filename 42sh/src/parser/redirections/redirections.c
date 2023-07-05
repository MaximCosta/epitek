/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-kilyan.cotten
** File description:
** redirections.c
*/

#include "mysh.h"

static char *error_message[] = {
    "No error\n",
    "Command not found\n",
    "Ambiguous output redirect.\n",
    "Ambiguous input redirect.\n",
    "Missing name for redirect.\n"
};

static int set_command(char **cmd, char **file, command_exec_t *command, int i)
{
    free(command->command);
    command->command = my_strdup(*cmd);
    do_free(*cmd, *file);
    return 0;
}

int check_simple_in(char **cmd, char **file, command_exec_t *command, \
                    int i)
{
    int r = get_redirection(command->command, file, cmd, (int[2]){'<', i});

    if (r != 0) {
        if (r != 4 || i == 2)
            print_error(error_message[r]);
        do_free(*cmd, *file);
        if (r != 4 || i == 2)
            return 1;
    }
    if (!*file[0] || r != 0) {
        if (!r)
            do_free(*cmd, *file);
        if (i == 1)
            return check_simple_in(cmd, file, command, 2);
        return 0;
    }
    command->file_in = my_strdup(*file);
    command->flag_in = i;
    return set_command(cmd, file, command, i);
}

int check_simple_out(char **cmd, char **file, command_exec_t *command,
                    int i)
{
    int r = get_redirection(command->command, file, cmd, (int[2]){'>', i});

    if (r != 0) {
        if (r != 4 || i == 2)
            print_error(error_message[r]);
        do_free(*cmd, *file);
        if (r != 4 || i == 2)
            return 1;
    }
    if (!*file[0] || r != 0) {
        if (!r)
            do_free(*cmd, *file);
        if (i == 1)
            return check_simple_out(cmd, file, command, 2);
        return 0;
    }
    command->file_out = my_strdup(*file);
    command->flag_out = i;
    return set_command(cmd, file, command, i);
}

static int parse_redirection_error(int i)
{
    if (i) {
        if ((i >> 1) % 2)
            return ERROR("Ambiguous input redirect.\n");
        if ((i >> 3) % 2)
            return ERROR("Ambiguous output redirect.\n");
        if ((i >> 4) % 2)
            return ERROR("Missing name for redirect.\n");
        return 1;
    }
    return 0;
}

int minishell_parse_redirection(minishell_t *minishell, \
                                command_t *command, char *cmd, char *file)
{
    command_exec_t *prev = NULL;
    command_exec_t *exec = command->exec;

    while (exec) {
        if (parse_redirection_error(
            check_simple_in(&cmd, &file, exec, 1) +
            ((exec->file_in && prev) << 1) +
            (check_simple_out(&cmd, &file, exec, 1) << 2) +
            ((exec->file_out && exec->next) << 3) +
            (((exec->file_out || exec->file_in) &&
            check_not_all_space(exec->command)) << 4)
        ))
        return 1;
        prev = exec;
        exec = exec->next;
    }
    return 0;
}
