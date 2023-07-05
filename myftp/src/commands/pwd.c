/*
** EPITECH PROJECT, 2023
** myftp [WSL: Ubuntu]
** File description:
** pwd
*/

#include "myftp.h"

int handle_pwd_command(char *buffer, client_t *client)
{
    char *concat = calloc(strlen(client->path) + 8, sizeof(char));
    (void) buffer;

    if (check_state(-1, client))
        return 1;
    if (concat == NULL)
        return 1;
    strcpy(concat, "257 \"");
    strcat(concat, client->path);
    strcat(concat, "\"\r\n");
    psend(client->socket.fd, concat);
    free(concat);
    return 1;
}
