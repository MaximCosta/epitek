/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** client_send
*/

#include "client.h"

int client_send(client_server_t *client)
{
    char **tmp = parse_send(client->buffer);
    client_event_private_message_received(tmp[0], tmp[1]);
    free(tmp[0]);
    free(tmp[1]);
    free(tmp);
    return 0;
}
