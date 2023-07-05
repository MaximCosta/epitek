/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** logout
*/

#include "server.h"

int logout(server_t *server, client_t *client)
{
    if (uuid_is_null(client->user_uuid))
        return dprintf(client->fd, "59-3 Please login first."ENDER);
    user_t *user = find_user_by_uuid(server, client->user_uuid);
    print_all_fds(server, user, "41-3", " logged out.");
    server_event_user_logged_out(user->unparsed_uuid);
    remove_client(server, client);
    return 1;
}
