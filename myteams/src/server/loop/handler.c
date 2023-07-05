/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** handler
*/

#include "server.h"

int handle_commands(server_t *server, client_t *client)
{
    if (!strcmp(client->cmd[0], "/login"))
        return login(server, client);
    if (!strcmp(client->cmd[0], "/help"))
        return help(server, client);
    if (!strcmp(client->cmd[0], "/logout"))
        return logout(server, client);
    if (!strcmp(client->cmd[0], "/users"))
        return users(server, client);
    if (!strcmp(client->cmd[0], "/user"))
        return user(server, client);
    if (!strcmp(client->cmd[0], "/send"))
        return send_message(server, client);
    if (!strcmp(client->cmd[0], "/messages"))
        return messages(server, client);
    if (!strcmp(client->cmd[0], "/close_server")) {
        server->keep_running = 0;
        return 1;
    }
    return dprintf(client->fd, "59-42 Unknown command."ENDER);
}

int handle_client(server_t *server, client_t *client)
{
    if (!(server->vread = read(client->fd, client->buffer, BUFF_SIZE))) {
        remove_client(server, client);
        return 0;
    }
    if (server->vread < 0)
        return printf("Error while reading from client."ENDER);
    if (remove_backslash_r(client->buffer) != 0) {
        strcat(client->unparsed_cmd, client->buffer);
        memset(client->buffer, 0, BUFF_SIZE);
        return 0;
    }
    strcat(client->unparsed_cmd, client->buffer);
    memset(client->buffer, 0, BUFF_SIZE);
    parse_command(client);
    memset(client->unparsed_cmd, 0, strlen(client->unparsed_cmd));
    if (handle_commands(server, client) == 1)
        return 0;
    free_command(client);
    return 0;
}

int handle_new_connection(server_t *server)
{
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int new_socket = server->new_socket;

    if ((new_socket = accept(server->server_fd, (struct sockaddr *)&address,
    (socklen_t *)&addrlen)) < 0)
        return 84;
    add_client(server, new_socket, &address);
    return 0;
}
