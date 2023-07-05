/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** client_users
*/

#include "client.h"

int client_users(client_server_t *client)
{
    char **tmp = {0};
    char *buf = client->buffer;
    int status = 0;
    int shift = 30;

    while (shift > 10) {
        tmp = parse_status(buf);
        status = tmp[2] == "online" ? 1 : 0;
        client_print_users(tmp[0], tmp[1], status);
        free(tmp[0]);
        free(tmp[1]);
        free(tmp);
        shift = strcspn(buf, "\n") + 1;
        buf += shift;
        shift = strcspn(buf, "\n");
    }
    return 0;
}
