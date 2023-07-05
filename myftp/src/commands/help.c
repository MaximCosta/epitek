/*
** EPITECH PROJECT, 2023
** myftp [WSL: Ubuntu]
** File description:
** other1
*/

#include "myftp.h"

int handle_help_command(char *buffer, client_t *client)
{
    (void) buffer;
    if (check_state(-1, client))
        return 1;
    psend(client->socket.fd, "214 Commands available: NOOP PWD\r\n");
    return 1;
}
