/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** add_remove_client
*/

#include "server.h"

void free_clients(server_t *server)
{
    client_t *client = server->clients;
    while (client) {
        client_t *next = client->next;
        remove_client(server, client);
        client = next;
    }
}

void add_client(server_t *server, int socket_fd, struct sockaddr_in *address)
{
    client_t *client = malloc(sizeof(client_t));
    client->next = server->clients;
    client->fd = socket_fd;
    server->clients = client;
    memset(client->user_uuid, 0, sizeof(uuid_t));
    memset(client->buffer, 0, BUFF_SIZE);
    memset(client->unparsed_cmd, 0, BUFF_SIZE);
    memset(client->unparsed_uuid, 0, UUID_L);
}

void remove_client(server_t *server, client_t *client)
{
    if (client == NULL) return;
    user_t *user = find_user_by_uuid(server, client->user_uuid);
    if (user)
        remove_fd_user(user, client->fd);
    close(client->fd);
    uuid_clear(client->user_uuid);
    free_command(client);
    if (server->clients == client) {
        server->clients = client->next;
    } else {
        client_t *prev = server->clients;
        while (prev->next != client)
            prev = prev->next;
        prev->next = client->next;
    }
    free(client);
}
