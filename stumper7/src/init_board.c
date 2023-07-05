/*
** EPITECH PROJECT, 2022
** duostumper05
** File description:
** init_board
*/

#include "my.h"

static void board_set_size(int *size, int ac, char *av[], int i)
{
    int val;

    if (ac <= i + 1)
        exit(84);
    if (is_digit(av[i + 1]) == 0)
        exit(84);
    val = atoi(av[i + 1]);
    if (val < 1)
        exit(84);
    *size = val;
}

static void player_set_char(char *player, int ac, char *av[], int i)
{
    if (ac <= i + 1)
        exit(84);
    if (strlen(av[i + 1]) != 1)
        return;
    *player = av[i + 1][0];
}

game_t *check_args(int ac, char *av[])
{
    game_t *game = calloc(sizeof(game_t), 1);

    if (game == NULL)
        exit(84);
    game->pl[0] = 'X';
    game->pl[1] = 'O';
    game->size = 3;
    for (int i = 0; i < ac; i++) {
        if (strcmp(av[i], "-p1") == 0)
            player_set_char(&game->pl[0], ac, av, i);
        if (strcmp(av[i], "-p2") == 0)
            player_set_char(&game->pl[1], ac, av, i);
        if (strcmp(av[i], "-s") == 0)
            board_set_size(&game->size, ac, av, i);
    }
    if (game->pl[0] == game->pl[1])
        exit(84);
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
