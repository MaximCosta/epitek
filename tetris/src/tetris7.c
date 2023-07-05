/*
** EPITECH PROJECT, 2022
** tetris [WSL: Ubuntu]
** File description:
** tetris7
*/

#include "../include/tetris.h"

void init_pieces(tetris_t *tetris)
{
    tetris->piece = my_calloc(sizeof(tetris_t), 1);
    tetris->next = my_calloc(sizeof(tetris_t), 1);
    get_next_piece(tetris);
    get_next_piece(tetris);
}

void main_tetris(tetris_t *tetris)
{
    if (tetris->old != tetris->player->seconds) {
        tetris->old = tetris->player->seconds;
        tetris->piece->cor.x--;
        if (tetris->piece->cor.x < 0) {
            tetris->piece->cor.x = tetris->input->size.x
                - tetris->pieces[tetris->piece->piece]->width;
            tetris->piece->cor.y++;
        }
    }
}

char *remove_back(char *s)
{
    for (int i = 0; s[i]; i++)
        if (s[i] == '\n')
            s[i] = '\0';
    return (s);
}

void render_next(tetris_t *tetris)
{
    int x = tetris->next->piece;
    int y = tetris->pieces[x]->height;

    mvwprintw(tetris->screen1, 0, 0, tetris->p1, tetris->player->high_score,
        tetris->player->minutes, tetris->player->seconds);
    box(tetris->screen2, 0, 0);
    mvwprintw(tetris->screen3, 0, 0, tetris->p2, tetris->player->score,
        tetris->player->level, tetris->player->lines,
        (y > 0 ? remove_back(tetris->pieces[x]->tetrimino[0]) : " "),
        (y > 1 ? remove_back(tetris->pieces[x]->tetrimino[1]) : " "),
        (y > 2 ? remove_back(tetris->pieces[x]->tetrimino[2]) : " "),
        (y > 3 ? remove_back(tetris->pieces[x]->tetrimino[3]) : " "),
        (y > 4 ? remove_back(tetris->pieces[x]->tetrimino[4]) : " "));
}

int loop_game(tetris_t *tetris)
{
    while (1) {
        refresh();
        train_tetris(tetris);
        main_tetris(tetris);
        render_next(tetris);
        wrefresh(tetris->screen3);
        wrefresh(tetris->screen2);
        wrefresh(tetris->screen1);
        clock_update(tetris);
    }
    endwin();
    return 0;
}
