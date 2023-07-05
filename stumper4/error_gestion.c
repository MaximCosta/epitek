/*
** EPITECH PROJECT, 2022
** Duostumper 4
** File description:
** error gestion
*/

#include <stdlib.h>
#include <string.h>

void file_error(char **av)
{
    if (strcmp(av[1], "-f") != 0)
        exit(84);
}

void size_error(char **av)
{
    if (strcmp(av[3], "-s") != 0)
        exit(84);
    for (int i = 0; av[4][i] != 0; i++) {
        if (!(av[4][i] >= '0' && av[4][i] <= '9'))
            exit(84);
    }
}

void error_gestion(int ac, char **av)
{
    if (ac != 3 && ac != 5)
        exit(84);
    file_error(av);
    if (ac == 5)
        size_error(av);
}
