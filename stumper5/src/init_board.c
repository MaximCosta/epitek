/*
** EPITECH PROJECT, 2022
** duostumper05
** File description:
** init_board
*/

#include "my.h"

game_t *check_args(int ac, char *av[])
{
    game_t *game = calloc(sizeof(game_t), 1);

    game->pl[0] = 'X';
    game->pl[1] = 'O';
    for (int i = 0; i < ac; i++) {
        if (strcmp(av[i], "-p1") == 0 && i + 1 < ac && strlen(av[i + 1]) == 1)
            game->pl[0] = av[i + 1][0];
        if (strcmp(av[i], "-p2") == 0 && i + 1 < ac && strlen(av[i + 1]) == 1)
            game->pl[1] = av[i + 1][0];
        if (strcmp(av[i], "-s") == 0 && i + 1 < ac)
            game->size = atoi(av[i + 1]);
    }
    if (game->size == 0)
        game->size = 3;
    return (game);
}

void init_board(game_t *game)
{
    game->board = calloc(sizeof(char *), game->size + 2);
    if (game->board == NULL)
        exit(84);
    for (int i = 0; i < game->size; i++) {
        game->board[i] = calloc(sizeof(char), game->size + 2);
        if (game->board[i] == NULL)
            exit(84);
        for (int j = 0; j < game->size; j++)
            game->board[i][j] = '.';
    }
}

void free_all(game_t *game)
{
    for (int i = 0; i < game->size; i++)
        free(game->board[i]);
    free(game->board);
    free(game);
}
