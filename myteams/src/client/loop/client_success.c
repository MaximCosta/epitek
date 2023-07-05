/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** success
*/

#include "client.h"

int handle_success(client_server_t *client)
{
    char code[6] = {0};
    strncpy(code, client->buffer, strcspn(client->buffer, " "));
    if (!strcmp(code, "41-2")) return client_log(client);
    if (!strcmp(code, "41-3")) return client_logout(client);
    if (!strcmp(code, "41-4")) return client_users(client);
    if (!strcmp(code, "41-5")) return client_user(client);
    if (!strcmp(code, "41-6")) return client_send(client);
}
