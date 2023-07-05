/*
** EPITECH PROJECT, 2023
** myftp [WSL: Ubuntu]
** File description:
** other
*/

#include "myftp.h"

int check_state(int status, client_t *client)
{
    if (status != client->state)
        return 1 && psend(client->socket.fd, "530 not logged in\r\n");
    return 0;
}
