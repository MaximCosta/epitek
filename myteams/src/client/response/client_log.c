/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** client_log
*/

#include "client.h"

int client_log(client_server_t *client)
{
    char **tmp = parse_uuid_and_name(client->buffer);
    client_event_logged_in(tmp[1], tmp[0]);
    free(tmp[0]);
    free(tmp[1]);
    free(tmp);
    return 0;
}
