/*
** EPITECH PROJECT, 2022
** count_rows_cols
** File description:
** stumper02
*/

#include "./include/my.h"

int count_rows(char *buffer)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            count++;
    return count;
}

int count_cols(char *buffer)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\n'; i++)
        count++;
    return count;
}

char **strdup_2d(char **map, int size_y, int size_x)
{
    char **new_map = malloc(sizeof(char *) * (size_y + 1));

    if (new_map == NULL)
        exit(84);
    for (int i = 0; i < size_y; i++)
        new_map[i] = NULL;
    for (int i = 0; map[i] != NULL; i++) {
        new_map[i] = malloc(sizeof(char) * (size_x + 1));
        if (new_map[i] == NULL)
            exit(84);
        for (int j = 0; map[i][j] != '\0'; j++)
            new_map[i][j] = map[i][j];
        new_map[i][size_x] = '\0';
    }
    return new_map;
}
