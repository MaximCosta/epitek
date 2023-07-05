/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** ls.c
*/

#include "../../../../../include/game/rpg.h"

void command_ls(shell_t *shell, char **args)
{
    file_t *file = shell->file;
    int i = 0;

    if (!file)
        return;
    if (file->type != T_DIRECTORY) {
        shell_print_line(shell, file->name);
        return;
    }
    for (i = 0; file->dir[i]; i++) {
        if (file->dir[i]->type == T_DIRECTORY) {
            shell_print(shell, file->dir[i]->name);
            shell_print(shell, "/\n");
        } else {
            shell_print(shell, file->dir[i]->name);
            shell_print(shell, "\n");
        }
    }
}