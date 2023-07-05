/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-kilyan.cotten
** File description:
** linked_list_create.c
*/

#include "mysh.h"

command_exec_t *node_create(char *command, command_exec_t *prev)
{
    command_exec_t *node = my_calloc(sizeof(command_exec_t));

    if (!node)
        return NULL;
    node->command = my_strdup(command);
    node->fd_in = 0;
    node->fd_out = 1;
    node->prev = prev;
    return node;
}

command_exec_t *add_node_at_back(command_exec_t **list, char *command)
{
    command_exec_t *tmp = *list;
    command_exec_t *prev = NULL;

    if (!tmp) {
        *list = node_create(command, prev);
        return *list;
    }
    while (tmp->next) {
        prev = tmp;
        tmp = tmp->next;
    }
    tmp->next = node_create(command, prev);
}

command_exec_t *detroy_list(command_exec_t *list)
{
    if (!list)
        return NULL;
    if (list->next)
        detroy_list(list->next);
    node_destroy(list);
    return NULL;
}

command_exec_t *node_destroy(command_exec_t *node)
{
    if (!node)
        return NULL;
    free(node->command);
    if (node->arg)
        for (int i = 0; node->arg[i]; i++)
            free(node->arg[i]);
    free(node->arg);
    free(node->file_in);
    free(node->file_out);
    free(node);
    return NULL;
}
