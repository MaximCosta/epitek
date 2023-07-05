/*
** EPITECH PROJECT, 2022
** tetris [WSL: Ubuntu]
** File description:
** tetris6
*/

#include "../include/tetris.h"

void init_screen(tetris_t *tetris)
{
    int mx = getmaxx(stdscr) / 2 - (tetris->input->size.x + 22) / 2;
    int my = getmaxy(stdscr) / 2 - MAX(tetris->input->size.y, 22) / 2 - 3;

    tetris->mx = getmaxx(stdscr);
    tetris->my = getmaxy(stdscr);
    tetris->screen4 = newwin(7, tetris->mx, 0, 0);
    tetris->screen1 = newwin(22, 12, my + 6, mx);
    tetris->screen2 = newwin(
        tetris->input->size.y + 2, tetris->input->size.x + 2, my + 6, mx + 12);
    tetris->screen3 = newwin(22, 12, my + 6, mx + tetris->input->size.x + 15);
}

void clock_update(tetris_t *tetris)
{
    clock_t end = clock();
    long int total = (double) (end - tetris->time) / CLOCKS_PER_SEC;

    tetris->player->milliseconds = (double) (end - tetris->time) / 50000;
    tetris->player->seconds = total % 60;
    tetris->player->minutes = total / 60;
}

void train_print(tetris_t *tetris, int x)
{
    int y = 0;
    int posx = 0;

    for (int j = 0; tetris->p3[j]; j++) {
        if (tetris->p3[j] == '\n') {
            y++;
            posx = 0;
            continue;
        }
        mvwprintw(tetris->screen4, y, ((x + posx++) % tetris->mx), "%c",
            tetris->p3[j]);
    }
}

void train_tetris(tetris_t *tetris)
{
    int move = tetris->player->milliseconds;
    int res = move > (tetris->mx + 49) ? 49 - (move - tetris->mx) : 49;

    train_print(tetris, move % (tetris->mx));
    wrefresh(tetris->screen4);
}

void get_next_piece(tetris_t *tetris)
{
    int r1 = 0;

    tetris->piece->piece = tetris->next->piece;
    tetris->piece->cor.x =
        tetris->input->size.x / 2 - tetris->pieces[r1]->width / 2;
    tetris->piece->cor.y = 0;
    tetris->piece->ori = 0;
    while (1) {
        r1 = rand() % tetris->nb_pieces;
        if (tetris->pieces[r1]->valid == 1)
            break;
    }
    tetris->next->piece = r1;
    tetris->next->cor.x = 0;
    tetris->next->cor.y = 0;
    tetris->next->ori = 0;
}
