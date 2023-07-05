/*
** EPITECH PROJECT, 2023
** myftp [WSL: Ubuntu]
** File description:
** list
*/

#include "myftp.h"

char *get_path(char *buffer, client_t *client)
{
    char *path = NULL;
    char *_path = NULL;
    printf("buffer: '%s' path: '%s' \r\n", buffer, client->path);
    if (buffer == NULL || strlen(buffer) == 1)
        path = strdup(client->path);
    else if (buffer[0] == '/')
        path = strdup(buffer);
    else {
        _path =
            malloc(sizeof(char) * (strlen(client->path) + strlen(buffer) + 2));
        sprintf(_path, "%s/%s", client->path, buffer);
        path = realpath(_path, NULL);
        free(_path);
    }
    if (path == NULL)
        psend(client->socket.fd, "500 Failed to get path\r\n");
    return path;
}

static int send_ls(client_t *client, char *path)
{
    char *cmd = calloc(sizeof(char), strlen(path) + 12);
    char buffer[BUFFER_SIZE + 1] = {0};
    FILE *stream = NULL;

    strcat(cmd, "/bin/ls -l ");
    strcat(cmd, path);
    stream = popen(cmd, "r");
    if (stream == NULL)
        return psend(
            client->socket.fd, "426 Connection closed; transfer aborted.\r\n");
    while (fgets(buffer, BUFFER_SIZE, stream) != NULL) {
        send(client->channel.fd, buffer, strlen(buffer), 0);
        memset(buffer, 0, BUFFER_SIZE);
    }
    pclose(stream);
    psend(client->socket.fd, "226 Directory send OK.\r\n");
    return 0;
}

static int fork_ls(char *path, client_t *client)
{
    pid_t pid = 0;

    if (connect_channel(client) == -1)
        return psend(client->socket.fd, "425 Failed to connect channel\r\n");
    pid = fork();
    if (pid == -1)
        return psend(client->socket.fd, "425 Failed to fork\r\n");
    if (pid == 0) {
        psend(client->socket.fd, "150 Here comes the directory listing.\r\n");
        send_ls(client, path);
        free(path);
        exit(0);
    }
    return 0;
}

int handle_list_command(char *buffer, client_t *client)
{
    char *path = NULL;

    if (check_state(-1, client)
        || is_channel_open(&client->channel, client->socket.fd) == false)
        return 1;
    path = get_path(buffer, client);
    if (path == NULL)
        return 1;
    fork_ls(path, client);
    close_channel(client);
    return 0;
}
