/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** client_unknown_user
*/

#include "client.h"

int client_unknown_user(client_server_t *client)
{
    char *tmp = parse_uuid(client->buffer);
    client_error_unknown_user(tmp);
    free(tmp);
    return 0;
}
