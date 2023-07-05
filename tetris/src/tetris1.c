/*
** EPITECH PROJECT, 2022
** tetris [WSL: Ubuntu]
** File description:
** tetris1
*/

#include "../include/tetris.h"

void init_input(input_t *input)
{
    input->debug = 0;
    input->key_drop = 258;
    input->key_left = 260;
    input->key_pause = 32;
    input->key_quit = 'q';
    input->key_right = 261;
    input->key_turn = 259;
    input->level = 1;
    input->next = true;
    input->size.x = 10;
    input->size.y = 20;
}

int check_pieces_line(char *line, int width)
{
    int count = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '*')
            count = i + 1;
        if (line[i] != '*' && line[i] != ' ' && line[i] != '\n')
            return (-1);
    }

    return (count > width ? -1 : count);
}

char **free_return_shape(char **shape, int check)
{
    if (check == -1) {
        for (int i = 0; shape[i] != NULL; i++)
            free(shape[i]);
        free(shape);
        return (NULL);
    }
    return (shape);
}

char **check_pieces_char(FILE *fp, api_t *pieces)
{
    char **shape = (char **) my_calloc2d(pieces->height + 10);
    char *line = NULL;
    size_t size = 0;
    int check = 0;

    shape[0] = NULL;
    for (int i = 0; getline(&line, &size, fp) != -1 && check != -1; i++) {
        shape[i] = my_strdump(line);
        check = check_pieces_line(shape[i], pieces->width);
        if (check >= 1 && i > (pieces->height - 1))
            check = -1;
        size = 0;
    }
    free(line);
    return (free_return_shape(shape, check));
}

int load_tetrimino_shape(FILE *fp, api_t *pieces)
{
    char **shape = check_pieces_char(fp, pieces);

    if (shape == NULL)
        return -1;
    pieces->tetrimino = shape;
    return 0;
}
