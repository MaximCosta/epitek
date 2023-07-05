/*
** EPITECH PROJECT, 2023
** myftp [WSL: Ubuntu]
** File description:
** client_manage
*/

#include "myftp.h"

int check_empty(char *buffer)
{
    if (buffer == NULL)
        return 1;
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] != ' ' && buffer[i] != '\r' && buffer[i] != '\n')
            return 0;
    return 1;
}

void close_channel(client_t *client)
{
    if (!is_none(client)) {
        if (client->channel.fd != 0)
            close(client->channel.fd);
        if (is_passive(client) && client->channel.server.fd)
            close(client->channel.server.fd);
    }
    memset(&client->channel, 0, sizeof(channel_t));
}

void remove_client(client_t *client)
{
    close(client->socket.fd);
    close_channel(client);
    memset(&client->socket, 0, sizeof(socket_t));
    free(client->path);
    client->state = 0;
    client->anonymous = 0;
    client->used = false;
}

int client_read(serv_t *serv, client_t *client)
{
    char buffer[BUFFER_SIZE];
    int nbytes = recv(client->socket.fd, buffer, sizeof(buffer), 0);
    (void) serv;

    for (int i = nbytes; i < BUFFER_SIZE; i++)
        buffer[i] = '\0';
    if (nbytes <= 0) {
        printf("Client on fd %d disconnected\n", client->socket.fd);
        remove_client(client);
        return 0;
    }
    if (check_empty(buffer))
        return 0;
    else
        return execute_command(client->socket.fd, buffer, client);
}
