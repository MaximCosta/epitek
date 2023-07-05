/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** help
*/

#include "server.h"

int help(server_t *server, client_t *client)
{
    dprintf(client->fd, "41-1 Refer to the documentation for the commands\n");
    return 0;
}
