/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** mkdir.c
*/

#include "../../../../../include/game/rpg.h"

void command_touch(shell_t *shell, char **args)
{
    if (!args[1]) {
        shell_print(shell, "mkdir: missing file operand\n");
        return;
    }
    for (int i = 1; args[i]; i++) {
        my_touch(&shell->file, args[i]);
    }
}