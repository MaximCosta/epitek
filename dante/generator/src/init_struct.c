/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-dante-maxim.costa
** File description:
** init_struct
*/

#include "../include/my.h"

generator_t *init_struct(int width, int height)
{
    generator_t *new_maze = malloc(sizeof(generator_t));
    srand(time(NULL));

    new_maze->width = width;
    new_maze->height = height;
    new_maze->map = malloc(sizeof(int *) * new_maze->height);
    for (int x = 0; x < height; x++) {
        new_maze->map[x] = malloc(sizeof(int) * new_maze->width);
    }
    for (int i = 0; i < height; i += 2) {
        for (int j = 0; j < width; j += 2) {
            new_maze->map[i][j] = rand() % 10;
            new_maze->map[i][j+1] = -1;
        }
        for (int l = 0; l < width && i+1 < height; l++)
            new_maze->map[i+1][l] = -1;
    }
    return new_maze;
}

void free_all(generator_t *maze)
{
    for (int x = 0; x < maze->height; x++)
        free(maze->map[x]);
    free(maze->map);
    free(maze);
}
