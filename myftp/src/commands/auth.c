/*
** EPITECH PROJECT, 2023
** myftp [WSL: Ubuntu]
** File description:
** auth
*/

#include "myftp.h"

int handle_user_command(char *buffer, client_t *client)
{
    if (check_state(0, client))
        return 1;

    if (strcmp(buffer, "Anonymous") == 0 || strcmp(buffer, "anonymous") == 0) {
        client->anonymous = 1;
        client->state = 1;
        return psend(client->socket.fd, "331 enter password\r\n");
    }
    client->anonymous = 0;
    client->state = 1;
    return psend(client->socket.fd, "331 enter password\r\n");
}

int handle_pass_command(char *buffer, client_t *client)
{
    if (check_state(1, client))
        return 1;
    (void) buffer;
    if (client->anonymous == 1) {
        client->state = -1;
        return psend(client->socket.fd, "230 logged in\r\n");
    }
    return psend(client->socket.fd, "530 not logged in\r\n");
}

int handle_quit_command(char *buffer, client_t *client)
{
    (void) buffer;
    psend(client->socket.fd, "221 Goodbye\r\n");
    remove_client(client);
    return 0;
}
