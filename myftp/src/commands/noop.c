/*
** EPITECH PROJECT, 2023
** myftp [WSL: Ubuntu]
** File description:
** noop
*/

#include "myftp.h"

int handle_noop_command(char *buffer, client_t *client)
{
    (void) buffer;

    if (check_state(-1, client))
        return 1;
    return psend(client->socket.fd, "200 OK\r\n");
}
