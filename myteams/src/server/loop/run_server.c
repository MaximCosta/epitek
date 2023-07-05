/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** run_server
*/

#include "server.h"

static int add_clients_to_set(server_t *server)
{
    client_t *client = NULL;

    for (client = server->clients; client; client = client->next) {
        if (client->fd > 0)
            FD_SET(client->fd, &server->readfds);
    }
    return 0;
}

static int handle_server_activity(server_t *server)
{
    client_t *temp;
    client_t *client;

    if (select(BUFF_SIZE, &server->readfds, &server->writefds,
    NULL, NULL) < 0) return printf("Select failed."ENDER);
    if (FD_ISSET(server->server_fd, &server->readfds) &&
    handle_new_connection(server) != 0)
        return -1;
    for (client = server->clients; client; client = temp) {
        temp = client->next;
        if (!FD_ISSET(client->fd, &server->readfds)) continue;
        if (handle_client(server, client) != 0) return -1;
    }
    return 0;
}

int run_server(server_t *server)
{
    while (server->keep_running) {
        FD_ZERO(&server->readfds);
        FD_ZERO(&server->writefds);
        FD_SET(server->server_fd, &server->readfds);
        FD_SET(server->server_fd, &server->writefds);
        if (add_clients_to_set(server) != 0)
            return printf("Error while adding clients to set."ENDER);
        if (handle_server_activity(server) != 0)
            return printf("Error while handling server activity."ENDER);
    }
    free_server(server);
    return 0;
}
