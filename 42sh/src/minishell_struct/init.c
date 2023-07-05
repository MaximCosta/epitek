/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-kilyan.cotten
** File description:
** init.c
*/

#include "mysh.h"

minishell_t *minishell_init(char **env)
{
    minishell_t *minishell = my_calloc(sizeof(minishell_t));

    if (!minishell)
        return NULL;
    for (int i = 0; env[i]; i++)
        minishell_env_append_string(minishell, env[i]);
    minishell->input_size = 300;
    minishell->input = my_calloc(sizeof(char) * minishell->input_size);
    minishell->exit = 1;
    minishell->home = minishell_getenv(minishell, "HOME");
    minishell_set_path(minishell);
    minishell_set_username(minishell);
    return minishell;
}

minishell_t *minishell_destroy(minishell_t *minishell)
{
    free(minishell->input);
    if (minishell->path) {
        for (int i = 0; minishell->path[i]; i++)
            free(minishell->path[i]);
        free(minishell->path);
    }
    free(minishell->oldpwd);
    free(minishell->user_name);
    minishell_env_free(minishell);
    minishell_env_to_str_free(minishell->env_save);
    free(minishell);
    return NULL;
}

command_t *minishell_parser_commands_free(command_t *head)
{
    if (!head)
        return NULL;
    minishell_parser_commands_free(head->next);
    free(head->command);
    detroy_list(head->exec);
    free(head);
    return NULL;
}

void minishell_clear_command(minishell_t *minishell)
{
    minishell_parser_commands_free(minishell->commands);
}
