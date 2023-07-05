/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** mkdir.c
*/

#include "../../../../../include/game/rpg.h"

void command_cd(shell_t *shell, char **args)
{
    file_t *file = shell->file;

    if (args[1] && args[2]) {
        shell_print(shell, "cd: too many arguments\n");
        return;
    }
    if (!args[1])
        file = my_get_path(&file, "/");
    else
        file = my_get_path(&file, args[1]);
    if (!file || file->type != T_DIRECTORY) {
        shell_print(shell, "cd: ");
        shell_print(shell, args[1]);
        shell_print(shell, ": ");
        shell_print_line(shell, !file ? "No such file or directory" :
                                        ": Not a directory");
        return;
    }
    shell->file = file;
}