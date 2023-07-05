/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** main
*/

#include "server.h"

static int help_display(int return_value)
{
    printf("USAGE: ./myteams_server port\n\n");
    printf("\tport\tis the port number on which"
    " the server socket listens.\n");
    return (return_value);
}

int main(int ac, char **av)
{
    server_t server = { 0 };

    if (ac != 2)
        return (help_display(84));
    if (!strcmp(av[1], "-help"))
        return (help_display(0));
    if (atoi(av[1]) == 0 || atoi(av[1]) > 65535)
        return (84);
    if (setup_server(&server, atoi(av[1])) == 84)
        return (84);
    if (run_server(&server) != 0)
        return (84);
    return (0);
}
