/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** create_user
*/

#include "server.h"

user_t *user_exists(server_t *server, char *username)
{
    user_t *user = server->users;

    while (user) {
        if (!strcmp(user->username, username)) return user;
        user = user->next;
    }
    return NULL;
}

user_t *find_user_by_uuid(server_t *server, uuid_t uuid)
{
    user_t *user = server->users;

    while (user) {
        if (!uuid_compare(user->uuid, uuid)) return user;
        user = user->next;
    }
    return NULL;
}

user_t *add_fd_user(user_t *user, int fd)
{
    user->fd[user->len_fd] = fd;
    user->len_fd++;
    return user;
}

user_t *remove_fd_user(user_t *user, int fd)
{
    int i = 0;

    while (i < user->len_fd && user->fd[i] != fd) i++;
    for (; i < user->len_fd; i++)
        user->fd[i] = user->fd[i + 1];
    user->len_fd--;
    return user;
}

user_t *create_user(server_t *server, client_t *client)
{
    user_t *user = calloc(1, sizeof(user_t));
    user_t *tmp = server->users;
    strcpy(user->username, client->cmd[1]);
    user->created_at = time(NULL);
    user->fd = calloc(1, sizeof(int) * 100);
    user->fd[0] = client->fd;
    user->len_fd = 1;
    user->next = NULL;
    uuid_generate(user->uuid);
    uuid_unparse(user->uuid, user->unparsed_uuid);
    while (tmp && tmp->next) tmp = tmp->next;
    if (tmp)
        tmp->next = user;
    else
        server->users = user;
    uuid_copy(client->user_uuid, user->uuid);
    strncpy(client->unparsed_uuid, user->unparsed_uuid, UUID_L);
    save_users(server);
    return user;
}
