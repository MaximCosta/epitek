/*
** EPITECH PROJECT, 2021
** minishell2
** File description:
** split.c
*/

#include "mysh.h"

/*
    Values of values tab
    0 : int in_quotes;
    1 : char quote_char;
    2 : int in_backquotes;
    3 : int error_back;
*/

int number_of_commands(char *command_line, char c)
{
    int nb_commands = 0;
    int values[4] = {0, 0, 0, 0};

    for (int i = 0; command_line[i]; i++) {
        if (!values[0] && command_line[i] == c)
            nb_commands++;
        if (command_line[i] == '"' || command_line[i] == '\'') {
            values[0] ^= (values[0] && command_line[i] == values[1]) ||
            !values[0];
            values[1] = values[0] ? command_line[i] : 1;
        }
        if (command_line[i] == '`')
            values[2] ^= 1;
    }
    if (values[3])
        return -'`';
    if (values[0])
        return -values[1];
    return nb_commands + 1;
}

int len_of_command(char *command_line, char c)
{
    int i = 0;
    int in_quotes = 0;
    int quote_char = 0;

    while (command_line[i] != '\0') {
        if ((command_line[i] == '\'' || command_line[i] == '\"') &&
            (i && command_line[i - 1] != '\\')) {
            in_quotes = in_quotes && quote_char == command_line[i] ? 0 : 1;
            quote_char = quote_char == command_line[i] ? 0 : command_line[i];
        }
        if (command_line[i] == c && !in_quotes)
            return i;
        i++;
    }
    return i;
}

static char **split_command_error(char cc)
{
    print_error("Unmatched '");
    write(2, &cc, 1);
    print_error("'.\n");
    return NULL;
}

char **split_command_line(char *command_line, char c)
{
    int n_of_commands = number_of_commands(command_line, c);
    char **commands = NULL;
    int i = 0;
    int len = 0;

    if (n_of_commands < 0)
        return split_command_error(-n_of_commands);
    commands = my_calloc(sizeof(char *) * (n_of_commands + 1));
    if (!commands)
        return NULL;
    while (*command_line) {
        len = len_of_command(command_line, c);
        commands[i] = str_ndup(command_line, len);
        command_line += len + (command_line[len] == c ? 1 : 0);
        i++;;
    }
    return commands;
}
