/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** init_serv
*/

#include "server.h"

void free_server(server_t *server)
{
    if (!server) return;
    if (server->clients)
        free_clients(server);
    if (server->users)
        free_users(server);
    close(server->server_fd);
}

static int setup_server_bis(server_t *server)
{
    server->address.sin_family = AF_INET;
    server->address.sin_addr.s_addr = INADDR_ANY;
    server->address.sin_port = htons(server->port);

    if (bind(server->server_fd, (struct sockaddr *)&server->address,
    sizeof(server->address)) < 0)
        return EXIT_FAIL;
    if (listen(server->server_fd, 3) < 0)
        return EXIT_FAIL;
    return 0;
}

int setup_server(server_t *server, int port)
{
    server->port = port;
    server->server_fd = 0;
    server->new_socket = 0;
    server->vread = 0;
    server->opt = 1;
    server->addrlen = sizeof(server->address);
    server->clients = NULL;
    server->users = NULL;
    server->keep_running = 1;
    load_users(server);
    if ((server->server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        return EXIT_FAIL;
    if (setsockopt(server->server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
    &server->opt, sizeof(server->opt)))
        return EXIT_FAIL;
    return setup_server_bis(server);
}
