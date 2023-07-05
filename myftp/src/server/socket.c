/*
** EPITECH PROJECT, 2023
** myftp [WSL: Ubuntu]
** File description:
** socket
*/

#include "myftp.h"

void socket_read_set(serv_t *serv)
{
    client_t *client = NULL;

    FD_ZERO(&serv->read_set);
    FD_SET(serv->socket->fd, &serv->read_set);
    for (int i = 0; serv->clients[i].used; i++) {
        client = &serv->clients[i];
        FD_SET(client->socket.fd, &serv->read_set);
        if (is_passive(client) && client->channel.server.fd != 0
            && client->channel.fd == 0)
            FD_SET(client->channel.server.fd, &serv->read_set);
    }
}

int create_socket(void)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int reuse = 1;

    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const char *) &reuse,
            sizeof(reuse))
        < 0) {
        perror("setsockopt");
        exit(1);
    }
    return sockfd;
}

socket_t *init_socket(int port)
{
    socket_t *socket = calloc(1, sizeof(socket_t));

    socket->fd = create_server(port);
    return socket;
}
