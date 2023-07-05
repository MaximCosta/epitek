/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** client_loop
*/

#include "client.h"

int handle_input(client_server_t *client)
{
    char tmp[BUFF_SIZE - 2] = {0};
    if (fgets(client->command, BUFF_SIZE, stdin) == NULL)
        exit(0);
    strncpy(tmp, client->command, strlen(client->command) - 1);
    sprintf(client->command, "%s\r\n", tmp);
    if (send(client->fd, client->command, strlen(client->command), 0) < 0)
        return printf("Error while sending command.\n");
    memset(client->command, 0, BUFF_SIZE);
    return 0;
}

int handle_server_response(client_server_t *client)
{
    if (!strncmp(RS_OK, client->buffer, 2))
        return handle_success(client);
    if (!strncmp(RS_KO, client->buffer, 2))
        return handle_error(client);
    return 0;
}

int handle_server_activity(client_server_t *client)
{
    int vread = 0;
    if (select(BUFF_SIZE, &client->readfds, &client->writefds, NULL, NULL) < 0)
        return printf("Select failed."ENDER);
    if (FD_ISSET(0, &client->readfds))
        if (handle_input(client) != 0) return 84;
    if (FD_ISSET(client->fd, &client->readfds)) {
        if (!(vread = read(client->fd, client->buffer, BUFF_SIZE))) {
            printf("Server disconnected."ENDER);
            client->keep_running = 0;
            return 0;
        }
        if (vread < 0)
            return printf("Error while reading server response."ENDER);
        handle_server_response(client);
        memset(client->buffer, 0, BUFF_SIZE);
    }
    return 0;
}

int client_loop(client_server_t *client)
{
    while (client->keep_running) {
        FD_ZERO(&client->readfds);
        FD_ZERO(&client->writefds);
        FD_SET(0, &client->readfds);
        FD_SET(client->fd, &client->readfds);
        FD_SET(client->fd, &client->writefds);
        if (handle_server_activity(client) != 0)
            return 84;
    }
    return 0;
}
