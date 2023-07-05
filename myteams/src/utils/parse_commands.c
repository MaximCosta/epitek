/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** parse_commands
*/

#include "server.h"


int count_ch(char *str, char ch)
{
    int i = 0;
    int count = 0;

    while (str[i]) {
        if (str[i++] == ch) count++;
    }
    return count;
}

void parse_command_bis(client_t *client)
{
    int count = count_ch(client->unparsed_cmd, '"');
    int i = 0;
    while (i < count) {
        char *start = strchr(client->unparsed_cmd, '"');
        if (!start) return;
        start++;
        char *end = strchr(start, '"');
        if (!end) return;
        int len = end - start;
        strncpy(client->cmd[i + 1], start, len);
        client->cmd[i + 1][len] = '\0';
        memmove(client->unparsed_cmd, end + 1, strlen(end + 1) + 1);
        count = count_ch(client->unparsed_cmd, '"');
        i++;
    }
}

void parse_command(client_t *client)
{
    int i = 0;
    int count = count_ch(client->unparsed_cmd, ' ');
    client->cmd = calloc(count + 2, sizeof(char *));
    if (client->cmd == NULL) return;
    for (int j = 0; j < count + 1; j++) {
        client->cmd[j] = calloc(1024, sizeof(char));
        if (client->cmd[j] == NULL) return;
    }
    while (client->unparsed_cmd[i] && client->unparsed_cmd[i] != ' ') i++;
    strncpy(client->cmd[0], client->unparsed_cmd, i);
    client->cmd[0][i] = '\0';
    if (i < strlen(client->unparsed_cmd) && client->unparsed_cmd[i] == ' ') {
        memmove(client->unparsed_cmd, client->unparsed_cmd + i + 1,
        strlen(client->unparsed_cmd + i + 1) + 1);
    } else
        client->unparsed_cmd[0] = '\0';
    parse_command_bis(client);
}
