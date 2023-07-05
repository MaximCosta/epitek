/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** main
*/

#include "client.h"

static int help_display(int return_value)
{
    printf("USAGE: ./myteams_cli ip port\n");
    printf("\tip\tis the server ip address on which"
    " the server socket listens.\n");
    printf("\tport\tis the port number on which"
    " the server socket listens.\n");
    return (return_value);
}

int main(int ac, char **av)
{
    client_server_t client;

    if (ac != 3)
        return (help_display(84));
    if (!strcmp(av[1], "-help"))
        return (help_display(0));
    if (init_client(&client, av) == 84)
        return (84);
    if (client_loop(&client) == 84)
        return (84);
    return (0);
}
