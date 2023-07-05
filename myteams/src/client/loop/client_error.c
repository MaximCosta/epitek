/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** client_error
*/

#include "client.h"

int handle_error(client_server_t *client)
{
    char code[6] = {0};
    strncpy(code, client->buffer, strcspn(client->buffer, " "));
    if (!strcmp(code, "59-3"))
        return client_unauthorized(client);
    if (!strcmp(code, "59-4"))
        return client_unknown_user(client);
}
