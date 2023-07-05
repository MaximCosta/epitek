/*
** EPITECH PROJECT, 2023
** myftp [WSL: Ubuntu]
** File description:
** myftp
*/

#include "myftp.h"

int manage_fd(serv_t *serv, int fd)
{
    for (int i = 0; i < serv->clients[i].used; i++) {
        if (serv->clients[i].socket.fd == fd)
            return client_read(serv, &serv->clients[i]);
        if (serv->clients[i].channel.server.fd == fd)
            return channel_read(serv, &serv->clients[i]);
    }
    return 0;
}

void loop(serv_t *serv)
{
    socket_read_set(serv);
    if (select(FD_SETSIZE, &serv->read_set, NULL, NULL, NULL) <= 0) {
        perror("select");
        exit(1);
    }
    if (FD_ISSET(serv->socket->fd, &serv->read_set))
        client_new(serv, true);
    for (int fd = 0; fd < FD_SETSIZE; fd++) {
        if (FD_ISSET(fd, &serv->read_set))
            manage_fd(serv, fd);
    }
}

int main(int argc, char **argv)
{
    serv_t *serv = init_serv(argc, argv);

    while (1)
        loop(serv);
    return 0;
}
