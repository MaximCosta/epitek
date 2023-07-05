/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** init_client
*/

#include "client.h"

int init_client(client_server_t *client, char **av)
{
    client->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->fd == -1)
        return 84;
    client->server_addr.sin_family = AF_INET;
    client->server_addr.sin_port = htons(atoi(av[2]));
    client->server_addr.sin_addr.s_addr = inet_addr(av[1]);
    if (connect(client->fd, (struct sockaddr *)&client->server_addr,
    sizeof(client->server_addr)) == -1) {
        close(client->fd);
        return 84;
    }
    client->keep_running = 1;
    memset(client->buffer, 0, BUFF_SIZE);
    memset(client->command, 0, BUFF_SIZE);
    client->name = NULL;
    return 0;
}
