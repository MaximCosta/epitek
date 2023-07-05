/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** client_messages
*/

#include "client.h"

int client_messages(client_server_t *client)
{
    char **tmp = {0};
    char *buffer = client->buffer;
    int shift = 0;
    while (buffer != NULL) {
        if (shift < 10) break;
        tmp = parse_messages(buffer);
        client_private_message_print_messages(tmp[0], atoi(tmp[1]), tmp[2]);
        shift = strcspn(buffer, "\n") + 1;
        buffer += shift;
        shift = strcspn(buffer, "\n") + 1;
        free(tmp[0]);
        free(tmp[1]);
        free(tmp[2]);
        free(tmp);
    }
    if (tmp[0]) free(tmp[0]);
    if (tmp[1]) free(tmp[1]);
    if (tmp[2]) free(tmp[2]);
    if (tmp) free(tmp);
    return 0;
}
