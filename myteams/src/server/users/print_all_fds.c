/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** print_all_fds
*/

#include "server.h"

void print_all_fds_user(user_t *user, char *format, ...)
{
    va_list args;
    va_start(args, format);

    for (int i = 0; i < user->len_fd; i++) {
        vdprintf(user->fd[i], format, args);
    }
}

int print_all_fds(server_t *server, user_t *user, char *code, char *message)
{
    user_t *tmp = server->users;

    while (tmp) {
        print_all_fds_user(tmp, "%s %s-[%s] %s"ENDER, code, user->username,
        user->unparsed_uuid, message);
        tmp = tmp->next;
    }
    return 0;
}
