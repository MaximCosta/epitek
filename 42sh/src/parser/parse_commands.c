/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-kilyan.cotten
** File description:
** parse_commands.c
*/

#include "mysh.h"

void commands_push(command_t **commands, char *str, int value)
{
    command_t *new = calloc(sizeof(command_t), 1);
    command_t *tmp = *commands;

    new->command = str;
    new->value = value;
    if (!tmp) {
        *commands = new;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    new->prev = tmp;
    tmp->next = new;
}

command_t *minishell_parser_error_free(command_t *head)
{
    if (!head)
        return NULL;
    minishell_parser_error_free(head->next);
    free(head);
    return NULL;
}

void minishell_parser_commands_extend(char **s, int n, char **to_parse)
{
    int tmp = 0;

    *s += n;
    tmp = strlen(to_parse[test_parse(*s, to_parse)]);
    **s = '\0';
    *s += tmp;
}

command_t *minishell_parser_commands(char *str, char **to_parse,
                                    int n, int tmp)
{
    char *s = strdup(str);
    command_t *head = NULL;

    while (*s) {
        n = number_to_next_parse(s, to_parse);
        if (n == -2)
            return minishell_parser_error_free(head);
        if (n == -1) {
            commands_push(&head, s, -1);
            break;
        }
        commands_push(&head, s, test_parse(s + n, to_parse) - 1);
        minishell_parser_commands_extend(&s, n, to_parse);
        if (!*s)
            commands_push(&head, s, -1);
    }
    return minishell_parser_commands_cleanstr(head);
}

int minishell_parse_commands(minishell_t *minishell)
{
    command_t *tmp = NULL;
    int n = 0;
    int tppm = 0;

    minishell->commands = minishell_parser_commands(minishell->input,
                                    (char *[]){";", "&&", "||", 0}, n, tppm);
    tmp = minishell->commands;
    if (!minishell->commands && SH_ERROR)
        return ERROR("%s\n", SH_ERROR)
    if (minishell_parse_commands_exec(minishell))
        return 1;
    while (tmp) {
        if (minishell_parse_redirection(minishell, tmp, NULL, NULL))
            return 1;
        tmp = tmp->next;
    }
    return 0;
}
