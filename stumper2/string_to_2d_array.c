/*
** EPITECH PROJECT, 2022
** Stumper 2
** File description:
** Game of life
*/

#include "./include/my.h"

void free_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}

char **mem_alloc(int cols, int rows)
{
    char **map = malloc(sizeof(char *) * (rows + 2));

    if (map == NULL)
        exit(84);
    for (int i = 0; i <= rows + 1; i++) {
        map[i] = malloc(sizeof(char) * (cols + 1));
        if (map[i] == NULL)
            exit(84);
        for (int j = 0; j <= cols; j++) {
            map[i][j] = 0;
        }
    }
    return map;
}

char **str_to_array(char *buffer, int cols, int rows)
{
    char **map = mem_alloc(cols, rows);
    int index = 0;
    int j = 0;

    for (int i = 0; buffer[i] != 0; i++) {
        if (buffer[i] == '\n') {
            map[j][index] = 0;
            index = 0;
            j++;
            continue;
        }
        map[j][index] = buffer[i];
        index++;
    }
    map[j] = NULL;
    return map;
}
