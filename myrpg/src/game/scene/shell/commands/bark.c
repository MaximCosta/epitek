/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** mkdir.c
*/

#include "../../../../../include/game/rpg.h"

void command_bark(shell_t *shell, char **args)
{
    sfSound_play(shell->sound);
}