/*
** EPITECH PROJECT, 2022
** duostumper05
** File description:
** print_board
*/

#include "my.h"

void board_template(game_t *game)
{
    if (printf("+") == -1)
        exit(84);
    for (int i = 0; i < game->size; i++)
        if (printf("-") == -1)
            exit(84);
    if (printf("+\n") == -1)
        exit(84);
}

void put_pl(game_t *game, int x, int y)
{
    if (game->board[y][x] == '.') {
        if (printf(" ") == -1)
            exit(84);
    } else {
        if (printf("%c", game->board[y][x]) == -1)
            exit(84);
    }
}

void print_board(game_t *gm)
{
    board_template(gm);
    for (int i = 0; i < gm->size; i++) {
        if (printf("|") == -1)
            exit(84);
        for (int j = 0; j < gm->size; j++)
            put_pl(gm, j, i);
        if (printf("|\n") == -1)
            exit(84);
    }
    board_template(gm);
}
