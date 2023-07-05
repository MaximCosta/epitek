/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** messages
*/

#include "server.h"

int messages(server_t *server, client_t *client)
{
    if (uuid_is_null(client->user_uuid))
        return dprintf(client->fd, "59-3 Please login first"ENDER);
    if (!client->cmd[1])
        return dprintf(client->fd, "59-1 Please specify an UUID"ENDER);
    uuid_t uuid;
    uuid_parse(client->cmd[1], uuid);
    user_t *user = find_user_by_uuid(server, uuid);
    if (!user)
        return dprintf(client->fd, "59-4 [%s] User not found"ENDER,
        client->cmd[1]);
    user_t *client_user = find_user_by_uuid(server, client->user_uuid);
    char *messages = get_messages(client_user->messages, user->uuid);
    printf("messages: %s\n", messages);
    print_all_fds_user(client_user, "41-7\n%s"ENDER, messages);
    free(messages);
    return 0;
}
