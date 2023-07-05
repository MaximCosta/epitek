/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** user
*/

#include "server.h"

int user(server_t *server, client_t *client)
{
    uuid_t uuid;
    if (uuid_is_null(client->user_uuid))
        return dprintf(client->fd, "59-3 Please login first"ENDER);
    user_t *client_user = find_user_by_uuid(server, client->user_uuid);
    if (client->cmd[1] == NULL)
        return dprintf(client->fd, "59-1 Please specify an UUID"ENDER);
    uuid_parse(client->cmd[1], uuid);
    user_t *user = find_user_by_uuid(server, uuid);
    if (user == NULL)
        return dprintf(client->fd, "59-4 [%s] User not found"ENDER,
        client->cmd[1]);
    int is_connected = user->len_fd > 0;
    print_all_fds_user(client_user, "41-5 %s-[%s] status : %s"ENDER,
    user->username, user->unparsed_uuid, is_connected ? "online" : "offline");
    return 0;
}
