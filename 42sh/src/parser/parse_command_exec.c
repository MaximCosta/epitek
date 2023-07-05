/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-kilyan.cotten
** File description:
** parse_command_exec.C
*/

#include "mysh.h"

int check_last_char(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    while (i >= 0 && (str[i] == ' ' || str[i] == '\t' || !str[i]))
        i--;
    return str[i] == '|';
}

int error_invalid_null_command(minishell_t *minishell, int n)
{
    if (n)
        print_error("Invalid null command.\n");
    minishell->exit_status = 1;
    return 84;
}

int minishell_parse_commands_exec2(minishell_t *minishell, char **commands,
                                    command_t *command)
{
    for (int j = 0; commands[j]; j++) {
        if (commands[j][0] == '\0') {
            free(commands[j]);
            return error_invalid_null_command(minishell, 1);
        }
        add_node_at_back(&command->exec, commands[j]);
        free(commands[j]);
    }
    return 0;
}

int minishell_parse_commands_exec(minishell_t *minishell)
{
    char **commands = NULL;
    command_t *tmp = minishell->commands;

    while (tmp) {
        if (check_last_char(tmp->command))
            return error_invalid_null_command(minishell, 1);
        commands = split_command_line(tmp->command, '|');
        if (!commands)
            return error_invalid_null_command(minishell, 1);
        if (minishell_parse_commands_exec2(minishell, commands, tmp))
            return 84;
        free(commands);
        tmp = tmp->next;
    }
    return 0;
}