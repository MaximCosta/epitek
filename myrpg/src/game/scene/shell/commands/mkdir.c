/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** mkdir.c
*/

#include "../../../../../include/game/rpg.h"

void command_mkdir(shell_t *shell, char **args)
{
    if (!args[1]) {
        shell_print(shell, "mkdir: missing operand\n");
        return;
    }
    for (int i = 1; args[i]; i++) {
        if (my_mkdir(&shell->file, args[i])) {
            shell_print(shell, "mkdir: cannot create directory '");
            shell_print(shell, args[i]);
            shell_print(shell, "':");
            shell_print_line(shell, (char *)ERROR_MSG);
        }
    }
}