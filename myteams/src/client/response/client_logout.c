/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** client_logout
*/

#include "client.h"

int client_logout(client_server_t *client)
{
    char **tmp = parse_uuid_and_name(client->buffer);
    client->keep_running = 0;
    client_event_logged_out(tmp[1], tmp[0]);
    free(tmp[0]);
    free(tmp[1]);
    free(tmp);
    return 0;
}
