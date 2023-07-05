/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** client_user
*/

#include "client.h"

int client_user(client_server_t *client)
{
    char **tmp = parse_status(client->buffer);
    int status = tmp[2] == "online" ? 1 : 0;
    client_print_user(tmp[0], tmp[1], status);
    return 0;
}
