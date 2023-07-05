/*
** EPITECH PROJECT, 2023
** myftp [WSL: Ubuntu]
** File description:
** pasv
*/

#include "myftp.h"

static void send_pasv(client_t *client, int iip[4], int port)
{
    char *buffer = malloc(sizeof(char) * 100);

    if (buffer == NULL)
        return;
    if (iip[0] == 0 && iip[1] == 0 && iip[2] == 0 && iip[3] == 0)
        iip = (int[4]){127, 0, 0, 1};
    sprintf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d).\r\n",
        iip[0], iip[1], iip[2], iip[3], port / 256, port % 256);
    psend(client->socket.fd, buffer);
    free(buffer);
}

int handle_pasv_command(char *buffer __attribute__((unused)), client_t *client)
{
    int s_soc = 0;
    socklen_t len = sizeof(sockaddr_in_t);
    char *sip = inet_ntoa(client->channel.server.sock_in.sin_addr);
    int iip[4] = {0};
    int port = 0;

    if (check_state(-1, client))
        return 1;
    close_channel(client);
    s_soc = create_server(0);
    if (s_soc == -1)
        return psend(client->socket.fd, "425 Can't open data connection.\r\n");
    getsockname(s_soc, (sockaddr_t *) &client->channel.server.sock_in, &len);
    sscanf(sip, "%d.%d.%d.%d", &iip[0], &iip[1], &iip[2], &iip[3]);
    port = ntohs(client->channel.server.sock_in.sin_port);
    send_pasv(client, iip, port);
    client->channel.status = PASSIVE;
    client->channel.server.fd = s_soc;
    return 0;
}
