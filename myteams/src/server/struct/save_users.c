/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** save_users
*/

#include "server.h"

void free_users(server_t *server)
{
    user_t *user = server->users;
    user_t *tmp = NULL;

    while (user) {
        tmp = user->next;
        for (int i = 0; i < user->len_fd; i++)
            close(user->fd[i]);
        free(user->fd);
        free(user);
        user = tmp;
    }
}

void add_user(server_t *server, char *username, char *uuid)
{
    user_t *user = calloc(1, sizeof(user_t));
    user_t *tmp = server->users;
    strcpy(user->username, username);
    strcpy(user->unparsed_uuid, uuid);
    uuid_parse(uuid, user->uuid);
    user->created_at = time(NULL);
    user->fd = calloc(1, sizeof(int) * 100);
    user->fd[0] = -1;
    user->len_fd = 0;
    user->next = NULL;
    if (!tmp) {
        server->users = user;
        return;
    }
    while (tmp->next) tmp = tmp->next;
    tmp->next = user;
}

void load_users(server_t *server)
{
    FILE *file = fopen("data/users", "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    char username[32] = {0};
    char uuid[37] = {0};

    if (!file) return;
    while ((read = getline(&line, &len, file)) != -1) {
        strncpy(username, line, strstr(line, "-[") - line);
        username[strstr(line, "-[") - line] = '\0';
        strncpy(uuid, strstr(line, "-[") + 2, 36);
        uuid[36] = '\0';
        add_user(server, username, uuid);
        server_event_user_loaded(uuid, username);
    }
    fclose(file);
    if (line) free(line);
}

void save_users(server_t *server)
{
    FILE *file = fopen("data/users", "w+");
    user_t *user = server->users;

    if (!file) return;
    while (user) {
        fprintf(file, user->next ? "%s-[%s]\n" : "%s-[%s]",
        user->username, user->unparsed_uuid);
        user = user->next;
    }
    fclose(file);
}
