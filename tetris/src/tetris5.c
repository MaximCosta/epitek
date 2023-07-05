/*
** EPITECH PROJECT, 2022
** tetris [WSL: Ubuntu]
** File description:
** tetris5
*/

#include "../include/tetris.h"

void debug_print2(tetris_t *tetris)
{
    for (int i = 0; tetris->pieces[i] != NULL; i++) {
        my_printf("Tetriminos '%s': ", tetris->pieces[i]->name);
        if (tetris->pieces[i]->valid == 0) {
            my_printf("error\n");
            continue;
        }
        my_printf("size %d*%d, color %d\n", tetris->pieces[i]->width,
            tetris->pieces[i]->height, tetris->pieces[i]->color);
        for (int j = 0; tetris->pieces[i]->tetrimino[j] != NULL; j++) {
            my_putstr(tetris->pieces[i]->tetrimino[j]);
        }
    }
}

void debug_print(tetris_t *tetris)
{
    input_t *i = tetris->input;

    my_printf("Key left: %s (%d)\n", keyname(i->key_left), i->key_left);
    my_printf("Key right: %s (%d)\n", keyname(i->key_right), i->key_right);
    my_printf("Key turn: %s (%d)\n", keyname(i->key_turn), i->key_turn);
    my_printf("Key drop: %s (%d)\n", keyname(i->key_drop), i->key_drop);
    my_printf("Key quit: %s (%d)\n", keyname(i->key_quit), i->key_quit);
    my_printf("Key pause: %s (%d)\n", keyname(i->key_pause), i->key_pause);
    my_printf("Next: %s\n", i->next ? "Yes" : "No");
    my_printf("Level: %d\n", i->level);
    my_printf("Size: %d*%d\n", i->size.y, i->size.x);
    my_printf("\n");
    my_printf("Number of tetriminos: %d\n", tetris->nb_pieces);
    debug_print2(tetris);
}

void init_ncurses(void)
{
    initscr();
    noecho();
    nocbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void load_screen_p(tetris_t *tetris, char *filename, char **part)
{
    int fp = open(filename, O_RDONLY);
    struct stat st;
    char *buffer = NULL;

    stat(filename, &st);
    buffer = my_calloc(sizeof(char), st.st_size + 1);
    read(fp, buffer, st.st_size);
    close(fp);
    *part = buffer;
}
