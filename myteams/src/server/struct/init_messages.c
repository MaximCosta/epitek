/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** init_messages
*/

#include "server.h"

void free_messages(messages_t *messages)
{
    messages_t *tmp = messages;
    while (tmp != NULL) {
        messages = messages->next;
        free(tmp);
        tmp = messages;
    }
}

char *get_messages(messages_t *messages, uuid_t other)
{
    char *res = calloc(1, sizeof(char));
    messages_t *tmp = messages;
    char sender_uuid[37];
    while (tmp) {
        if (uuid_compare(tmp->created_by, other) != 0 &&
        uuid_compare(tmp->receiver, other) != 0) {
            tmp = tmp->next;
            continue;
        }
        if (uuid_is_null(tmp->created_by)) {
            tmp = tmp->next;
            continue;
        }
        uuid_unparse(tmp->created_by, sender_uuid);
        res = realloc(res, sizeof(char) * (strlen(res) + 200));
        sprintf(res, "[%s] (%ld) %s\n", sender_uuid, tmp->created_at,
        tmp->body);
        tmp = tmp->next;
    }
    return res;
}

void add_messages(messages_t *messages,
uuid_t sender, uuid_t receiver, char *body)
{
    messages_t *new_message = create_message(sender, receiver, body);
    if (messages == NULL) {
        messages = new_message;
        return;
    }
    messages_t *tmp = messages;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_message;
}

messages_t *create_message(uuid_t sender, uuid_t receiver, char *body)
{
    messages_t *message = malloc(sizeof(messages_t));
    message->created_at = time(NULL);
    uuid_copy(message->created_by, sender);
    uuid_copy(message->receiver, receiver);
    strcpy(message->body, body);
    message->next = NULL;
    return message;
}
