/*
** EPITECH PROJECT, 2022
** src/algo
** File description:
** well, real programmers use ed
*/

#include "sand.h"

int is_supof1(sand_t *sand, int y)
{
    for (int x = 0; x < sand->sy; x++)
        if (sand->maps[x][y] >= 4) {
            sand->cx = x;
            sand->cy = y;
            return (1);
        }
    return (0);
}

int is_supof(sand_t *sand)
{
    sand->cx = -1;
    sand->cy = -1;
    for (int y = 0; y < sand->sy; y++)
        if (is_supof1(sand, y))
            return (1);
    return (0);
}

