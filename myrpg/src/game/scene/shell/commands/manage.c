/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** manage.c
*/

#include "../../../../../include/game/rpg.h"

static const shell_commands_t shell_commands[] = {
    {"clear", &command_clear},
    {"exit", &command_exit},
    {"help", &command_help},
    {"history", &command_history},
    {"rpg", &command_rpg},
    {"ls", &command_ls},
    {"pwd", &command_pwd},
    {"mkdir", &command_mkdir},
    {"cd", &command_cd},
    {"touch", &command_touch},
    {"bark", &command_bark},
    {"tartine", &tartine},
    {0, 0},
};

static int do_command(shell_t *shell, char **args)
{
    for (int i = 0; shell_commands[i].name; i++) {
        if (equal(*args, shell_commands[i].name)) {
            shell_commands[i].func(shell, args);
            return 1;
        }
    }
    return 0;
}

void command_manage(shell_t *shell)
{
    char **command_parse = NULL;
    if (!shell->cmd->len)
        return;
    command_parse = shell_command_parse(shell->cmd->str);
    if (!command_parse || !command_parse[0])
        return;
    shell_history_append(shell, shell->cmd->str);
    if (do_command(shell, command_parse))
        return;
    shell_print(shell, *command_parse);
    shell_print(shell, ": command not found\n");
}