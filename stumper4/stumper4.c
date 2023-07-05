/*
** EPITECH PROJECT, 2022
** stumper4
** File description:
** C-x C-c
*/

#include "my.h"

void grid_print(data_t *data, int in, int total)
{
    char **grid = data->grid;
    int size = data->size;

    printf("%d/%d words inserted in the grid.\n", in, total);
    for (int i = 0; i < size + 2; i++)
        printf("+");
    printf("\n");
    for (int i = 0; i < size; i++)
        printf("|%*.*s|\n", size, size, grid[i]);
    for (int i = 0; i < size + 2; i++)
        printf("+");
    printf("\n");
}

void free_all(data_t *data)
{
    for (int i = 0; i < data->size; i++)
        free(data->grid[i]);
    for (int i = 0; data->words[i]; i++)
        free(data->words[i]);
    for (int i = 0; data->word[i]; i++)
        free(data->word[i]);
    free(data->words);
    free(data->word);
    free(data->grid);
    free(data);
}

int get_next(data_t *data)
{
    char **word = data->word;
    int id_min = -1;
    int min = -1;
    int size = data->size;
    int id = 0;

    while (word[id]) {
        if (strlen(word[id]) <= size && word[id][0] != '.'
            && (min == -1 || strlen(word[id]) < min)) {
            min = strlen(word[id]);
            id_min = id;
        };
    }
    return (id_min);
}

int insert(data_t *data, char *word, int x, int y)
{
    char **grid = data->grid;
    int size = data->size;
    int i = 0;

    if (grid[y] == NULL)
        grid[y] = calloc(size + 1, sizeof(char));
    if (grid[y] == NULL)
        exit(84);
    for (; word[i]; grid[y][x++] = word[i++]);
    return x;
}

void fill_random(data_t *data)
{
    char **grid = data->grid;

    for (int y = 0; y < data->size; y++) {
        if (data->grid[y] == NULL)
            data->grid[y] = calloc(data->size + 1, sizeof(char));
        for (int x = 0; x < data->size; x++)
            grid[y][x] = grid[y][x] == 0 ? (rand() % 26) + 97 : grid[y][x];
    }
}
