/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** send
*/

#include "server.h"

int send_message(server_t *server, client_t *client)
{
    if (uuid_is_null(client->user_uuid))
        return dprintf(client->fd, "59-3 Please login first."ENDER);
    if (!client->cmd[1] || !client->cmd[2])
        return dprintf(client->fd, "59-1 Wrongs arguments - UUID BODY."ENDER);
    uuid_t uuid;
    uuid_parse(client->cmd[1], uuid);
    user_t *receiver = find_user_by_uuid(server, uuid);
    if (!receiver)
        return dprintf(client->fd,
        "59-4 [%s] User not found."ENDER, client->cmd[1]);
    user_t *sender = find_user_by_uuid(server, client->user_uuid);
    add_messages(receiver->messages, sender->uuid, receiver->uuid,
    client->cmd[2]);
    add_messages(sender->messages, sender->uuid, receiver->uuid,
    client->cmd[2]);
    dprintf(client->fd, "41-6 [%s] %s"ENDER, sender->unparsed_uuid,
    client->cmd[2]);
    server_event_private_message_sended(sender->unparsed_uuid,
    receiver->unparsed_uuid, client->cmd[2]);
    return 0;
}
