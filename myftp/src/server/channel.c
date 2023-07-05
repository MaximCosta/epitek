/*
** EPITECH PROJECT, 2023
** myftp [WSL: Ubuntu]
** File description:
** channel
*/

#include "myftp.h"

bool is_channel_open(channel_t *channel, int fd)
{
    if (channel->status == NONE) {
        psend(fd, "425 Use PORT or PASV first.\r\n");
        return false;
    }
    return true;
}

static int new_fd(socket_t *socket)
{
    sockaddr_in_t sock_client = {0};
    socklen_t sockaddr_client_size = sizeof(sock_client);
    int client_fd =
        accept(socket->fd, (sockaddr_t *) &sock_client, &sockaddr_client_size);
    if (client_fd == -1) {
        perror("accept");
        return -1;
    }
    return client_fd;
}

static int connect_active(client_t *client)
{
    int fd = create_socket();

    if (fd == -1)
        return -1;
    if (connect(fd, (sockaddr_t *) &client->channel.server.sock_in,
            sizeof(sockaddr_in_t))
        == -1)
        return -1;
    client->channel.fd = fd;
    return 0;
}

static int connect_passive(client_t *client)
{
    int new_client = new_fd(&client->channel.server);

    if (new_client == -1)
        return -1;
    client->channel.fd = new_client;
    return 0;
}

int connect_channel(client_t *client)
{
    if (client->channel.status == ACTIVE && client->channel.fd == 0) {
        return connect_active(client);
    } else if (client->channel.fd == 0 && client->channel.status == PASSIVE)
        return connect_passive(client);
    else
        return 0;
}
