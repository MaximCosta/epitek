/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** pwd.c
*/

#include "../../../../../include/game/rpg.h"

void command_pwd(shell_t *shell, char **args)
{
    char pwd[1024] = {0};

    shell_print_line(shell, get_cwd(shell->file, pwd));
}