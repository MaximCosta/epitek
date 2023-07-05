/*
** EPITECH PROJECT, 2022
** print_map
** File description:
** stumper
*/

#include "sand.h"

int print_map(sand_t *sand)
{
    for (int y = 0; y < sand->sy; y++) {
        for (int x = 0; x < sand->sx; x++) {
            printf("%c", sand->base[sand->maps[y][x]]);
        }
        printf("\n");
    }
    return 0;
}

void free_all(sand_t *sand, char *map)
{
    for (int i = 0; sand->maps[i] != NULL; i++)
        free(sand->maps[i]);
    free(sand->maps);
    free(map);
    free(sand);
}
