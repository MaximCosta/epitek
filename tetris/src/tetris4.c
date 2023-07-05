/*
** EPITECH PROJECT, 2022
** tetris [WSL: Ubuntu]
** File description:
** tetris4
*/

#include "../include/tetris.h"

static const struct option long_options[] = {{"help", 2, NULL, 'h'},
    {"level={%d}", 1, NULL, 'L'}, {"key-left={%d}", 1, NULL, 'l'},
    {"key-right={%d}", 1, NULL, 'r'}, {"key-turn={%d}", 1, NULL, 't'},
    {"key-drop={%d}", 1, NULL, 'd'}, {"key-quit={%d}", 1, NULL, 'q'},
    {"key-pause={%d}", 1, NULL, 'p'}, {"map-size={%d,%d}", 1, NULL, 'm'},
    {"without-next", 2, NULL, 'w'}, {"debug", 2, NULL, 'D'}, {0, 0, 0, 0}};

void free_all(tetris_t *tetris)
{
    for (int i = 0; tetris->pieces[i] != NULL; i++) {
        free(tetris->pieces[i]->name);
        if (tetris->pieces[i]->valid == 0)
            continue;
        for (int j = 0; tetris->pieces[i]->tetrimino[j] != NULL; j++) {
            free(tetris->pieces[i]->tetrimino[j]);
        }
        free(tetris->pieces[i]->tetrimino);
        free(tetris->pieces[i]);
    }
    if (tetris->pieces != NULL)
        free(tetris->pieces);
    free(tetris->input);
    free(tetris);
    exit(0);
}

void flags_debug2(int opt, input_t *input, char **av)
{
    switch (opt) {
        case 'd':
            return verif_input((int[3]){258, -1, 1}, &input->key_drop, av);
        case 'q':
            return verif_input((int[3]){'q', -1, 1}, &input->key_quit, av);
        case 'p':
            return verif_input((int[3]){32, -1, 1}, &input->key_pause, av);
        case 'w':
            return verif_bool_rev(&input->next, av);
        case 'D':
            return verif_bool(&input->debug, av);
        case 'm':
            return map_size(input);
    }
    exit(84);
}

void flags_debug(int opt, input_t *input, char **av)
{
    switch (opt) {
        case 'h':
            return verif_bool(&input->help, av);
        case 'L':
            return verif_input((int[3]){1, -1, 1}, &input->level, av);
        case 'l':
            return verif_input((int[3]){260, -1, 1}, &input->key_left, av);
        case 'r':
            return verif_input((int[3]){261, -1, 1}, &input->key_right, av);
        case 't':
            return verif_input((int[3]){259, -1, 1}, &input->key_turn, av);
    }
    flags_debug2(opt, input, av);
}

void arguments(int ac, char **av, input_t *input)
{
    int opt = 0;
    char optstring[] = "Llrtdqpm:wDh::";
    int opt_index = 0;

    while (
        (opt = getopt_long(ac, av, optstring, long_options, &opt_index)) != -1)
        flags_debug(opt, input, av);
}
