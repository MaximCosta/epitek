/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** history.c
*/

#include "../../../../include/game/rpg.h"

void shell_history_append(shell_t *shell, char *cmd)
{
    shell_history_t *new = my_calloc(sizeof(shell_history_t));
    shell_history_t *tmp = shell->history;

    new->cmd = str_create(cmd);
    if (!shell->history) {
        shell->history = new;
        return;
    }
    while (shell->history->next)
        shell->history = shell->history->next;
    new->prev = shell->history;
    shell->history->next = new;
    shell->history = new;
}
