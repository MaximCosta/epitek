/*
** EPITECH PROJECT, 2023
** myftp [WSL: Ubuntu]
** File description:
** check
*/

#include "myftp.h"

int check_args(int argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "-help") == 0) {
        printf("USAGE: ./myftp port path\n");
        printf("\tport is the port number on which ");
        printf("the server socket listens.\n");
        printf("\tpath is the path to the ");
        printf("home directory for the Anonymous user.\n");
        exit(0);
    }
    if (argc != 3) {
        printf("Usage: ./myftp [port] [path]\n");
        exit(1);
    }
    if (atoi(argv[1]) < 0 || atoi(argv[1]) > 65535
        || access(argv[2], F_OK) == -1) {
        printf("Invalid port number (0-65535) or path\n");
        exit(1);
    }
    return 1;
}
