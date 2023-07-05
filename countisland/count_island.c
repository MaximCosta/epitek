/*
** EPITECH PROJECT, 2021
** count_island
** File description:
** Count nbr island
*/

#include <stdlib.h>

void *array_len(char **world, int *x, int *y)
{
    while (world[*y])
        (*y)++;
    while (world[0][*x])
        (*x)++;
}

void island_contamination(char **world, int x, int y, char *count)
{
    int len_y = 0;
    int len_x = 0;
    int pos[4][2] = {{ x, y }, { x, y }, { x, y }, { x, y }};

    array_len(world, &len_x, &len_y);
    if (y > 0)
        pos[0][1] = y - 1;
    if (x < len_x - 1)
        pos[1][0] = x + 1;
    if (y < len_y - 1)
        pos[2][1] = y + 1;
    if (y > 0)
        pos[3][0] = x - 1;
    world[y][x] = *count;
    for (int i = 0; i < 4; i++) {
        if (world[pos[i][1]][pos[i][0]] == 'X')
            island_contamination(world, pos[i][0], pos[i][1], count);
    }
}

int add_verif(char **world, int x, int y, char *count)
{
    if (world[y][x] == 'X') {
        island_contamination(world, x, y, count);
        (*count)++;
    }
}

int count_island(char **world)
{
    char count = '0';

    for (int y = 0; world[y]; y++) {
        for (int x = 0; world[y][x]; x++) {
            add_verif(world, x, y, &count);
        } 
    }
    return count - 48;
}
