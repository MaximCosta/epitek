/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** free_command
*/

#include "server.h"

void free_command(client_t *client)
{
    if (!client) return;
    if (!client->cmd) return;
    for (int i = 0; client->cmd[i]; i++)
        free(client->cmd[i]);
    if (client->cmd)
        free(client->cmd);
}
