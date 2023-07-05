/*
** EPITECH PROJECT, 2022
** tetris [WSL: Ubuntu]
** File description:
** lib4
*/

#include "../include/tetris.h"

void verif_bool_rev(int *input, char **argv)
{
    if (optarg == NULL && argv[optind] != NULL && argv[optind][0] != '-')
        exit(84);
    *input = false;
}