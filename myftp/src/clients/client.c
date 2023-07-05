/*
** EPITECH PROJECT, 2023
** myftp [WSL: Ubuntu]
** File description:
** client
*/

#include "myftp.h"

client_t *client_init(void)
{
    client_t *clients = calloc(FD_SETSIZE + 1, sizeof(client_t));

    for (int i = 0; i < FD_SETSIZE; i++) {
        clients[i].anonymous = 0;
        clients[i].path = NULL;
        clients[i].state = 0;
        clients[i].used = false;
    }
    return clients;
}

void client_new(serv_t *serv, bool writing)
{
    sockaddr_in_t cddr;
    socklen_t clilen = sizeof(cddr);
    int connfd = accept(serv->socket->fd, (sockaddr_t *) &cddr, &clilen);
    int index = 0;
    for (; index < FD_SETSIZE; index++)
        if (!serv->clients[index].used)
            break;

    if (connfd < 0) {
        perror("accept");
        return;
    }
    printf("New %s:%d\n", inet_ntoa(cddr.sin_addr), ntohs(cddr.sin_port));
    if (writing)
        psend(connfd, "220 Welcome!\r\n");
    serv->clients[index].socket.fd = connfd;
    serv->clients[index].path = strdup(serv->default_path);
    serv->clients[index].used = true;
    serv->clients[index].serv = serv;
}
