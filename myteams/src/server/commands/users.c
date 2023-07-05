/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** users
*/

#include "server.h"

int users(server_t *server, client_t *client)
{
    if (uuid_is_null(client->user_uuid))
        return dprintf(client->fd, "59-3 Please login first."ENDER);
    user_t *tmp = server->users;
    user_t *user = find_user_by_uuid(server, client->user_uuid);
    while (tmp) {
        print_all_fds_user(user, "41-4 %s-[%s] status : %s"ENDER,
        tmp->username, tmp->unparsed_uuid,
        tmp->len_fd > 0 ? "online" : "offline");
        tmp = tmp->next;
    }
    return 0;
}
