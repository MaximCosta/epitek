/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** login
*/

#include "server.h"

int login(server_t *server, client_t *client)
{
    user_t *tmp = NULL;
    if (!client->cmd[1]) {
        dprintf(client->fd, "59-1 Please specify the username."ENDER);
        return 0;
    }
    if (!uuid_is_null(client->user_uuid))
        return dprintf(client->fd, "59-2 You are already logged in."ENDER);
    if ((tmp = user_exists(server, client->cmd[1]))) {
        add_fd_user(tmp, client->fd);
        uuid_copy(client->user_uuid, tmp->uuid);
        strcpy(client->unparsed_uuid, tmp->unparsed_uuid);
        server_event_user_logged_in(tmp->unparsed_uuid);
        return print_all_fds(server, tmp, "41-2"," logged in.");
    }
    tmp = create_user(server, client);
    server_event_user_created(tmp->unparsed_uuid, tmp->username);
    server_event_user_logged_in(tmp->unparsed_uuid);
    return print_all_fds(server, tmp, "41-2"," logged in.");
}
