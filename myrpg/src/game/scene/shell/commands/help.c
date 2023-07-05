/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** help.c
*/

#include "../../../../../include/game/rpg.h"

void command_help(shell_t *shell, char **args)
{
    shell_print(shell, "\nCommands:\n");
    shell_print(shell, "  rpg      - Start the RPG\n");
    shell_print(shell, "  tartine  - Start secret\n");
    shell_print(shell, "  clear    - Clear the terminal\n");
    shell_print(shell, "  exit     - Exit the terminal\n");
    shell_print(shell, "  history  - Show history of commands\n");
    shell_print(shell, "  cd       - Change current directory\n");
    shell_print(shell, "  cwd      - Show current PATH\n");
    shell_print(shell, "  mkdir    - Create folder\n");
    shell_print(shell, "  touch    - Create file\n");
    shell_print(shell, "  help     - Show this help\n\n");
    shell_print(shell, "  bark     - Bark bark\n");
}