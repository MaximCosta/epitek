/*
** EPITECH PROJECT, 2023
** myftp [WSL: Ubuntu]
** File description:
** cwd
*/

#include "myftp.h"

int handle_cwd_command(char *buffer, client_t *client)
{
    char *path = get_path(buffer, client);

    if (path == NULL)
        return -1;
    if (chdir(path) == -1) {
        psend(client->socket.fd, "550 Failed to change directory.\r\n");
        free(path);
        return -1;
    }
    free(client->path);
    client->path = path;
    psend(client->socket.fd, "250 Directory successfully changed.\r\n");
    return 0;
}
