/*
** EPITECH PROJECT, 2023
** myftp [WSL: Ubuntu]
** File description:
** init
*/

#include "myftp.h"

serv_t *init_serv(int argc, char **argv)
{
    serv_t *serv = calloc(check_args(argc, argv), sizeof(serv_t));
    serv->port = atoi(argv[1]);
    serv->default_path = realpath(argv[2], NULL);
    serv->socket = init_socket(serv->port);
    serv->clients = client_init();
    return serv;
}

int create_server(int port)
{
    int fd = create_socket();
    struct sockaddr_in sock_in = {0};

    if (fd == -1)
        return -1;
    sock_in.sin_family = AF_INET;
    sock_in.sin_port = htons(port);
    sock_in.sin_addr.s_addr = INADDR_ANY;
    if (bind(fd, (struct sockaddr *) &sock_in, sizeof(sock_in)) < 0) {
        perror("bind");
        close(fd);
        exit(1);
    }
    if (listen(fd, SOMAXCONN) < 0) {
        perror("listen");
        close(fd);
        exit(1);
    }
    return fd;
}
