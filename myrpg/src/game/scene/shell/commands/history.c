/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** history.c
*/

#include "../../../../../include/game/rpg.h"

static int get_len_history(shell_history_t *history)
{
    int len = 0;

    while (history) {
        len++;
        history = history->next;
    }
    return len;
}

static int get_len_nbr(int i)
{
    int len = 0;

    while (i > 0) {
        len++;
        i /= 10;
    }
    return len == 0 ? 1 : len;
}

void command_history(shell_t *shell, char **args)
{
    shell_history_t *tmp = shell->history;
    str_t *str = str_create_size(128);
    int len = 0;

    while (tmp && tmp->prev)
        tmp = tmp->prev;
    len = get_len_history(tmp);
    for (int i = 0; tmp; i++) {
        for (int j = 0; j < get_len_nbr(len) - get_len_nbr(i) + 1; j++)
            shell_print(shell, " ");
        str_add_nbr(str, i);
        shell_print(shell, str->str);
        shell_print(shell, " -  ");
        shell_print_line(shell, tmp->cmd->str);
        str_clear(str);
        tmp = tmp->next;
    }
    str_destroy(str);
}