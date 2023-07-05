/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** clear.c
*/

#include "../../../../../include/game/rpg.h"

void command_clear(shell_t *shell, char **args)
{
    for (int i = 0; i < shell->height; i++)
        str_clear(shell->str_lines[i]);
    shell->cursor_pos = 0;
    shell->cursor_pos_cmd = 0;
    shell->line = 0;
}