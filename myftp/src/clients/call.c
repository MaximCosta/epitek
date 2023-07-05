/*
** EPITECH PROJECT, 2023
** myftp [WSL: Ubuntu]
** File description:
** call
*/

#include "myftp.h"

int execute_command(int clientfd, char *buffer, client_t *client)
{
    char *command = strtok(buffer, " \r\n");
    command_map_t commands[] = {{"USER", handle_user_command},
        {"PASS", handle_pass_command}, {"CWD", handle_cwd_command},
        {"XCWD", handle_cwd_command}, {"CDUP", handle_cdup_command},
        {"QUIT", handle_quit_command}, {"NOOP", handle_noop_command},
        {"PWD", handle_pwd_command}, {"PASV", handle_pasv_command},
        {"HELP", handle_help_command}, {"LIST", handle_list_command},
        {NULL, NULL}};

    if (command == NULL)
        return psend(clientfd, "500 Syntax error\r\n");
    printf("<-(%d)- %s\n", clientfd, buffer);
    for (int i = 0; commands[i].key != NULL; i++) {
        if (strcmp(command, commands[i].key) == 0) {
            char *args = strtok(NULL, " \r ");
            return commands[i].handler(args, client);
        }
    }
    return psend(clientfd, "500 Unknown command\r\n");
}
