/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** prompt.c
*/

#include "../../../../include/game/rpg.h"

void display_prompt(shell_t *shell)
{
    char pwd[1024] = {0};

    shell_print(shell, get_cwd(shell->file, pwd));
    shell_print(shell, " $> ");
}