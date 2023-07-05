/*
** EPITECH PROJECT, 2022
** DuoStumper 3
** File description:
** replace map chars
*/

#include "sand.h"

int count_cols(char *buffer)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\n'; i++) {
        count++;
    }
    return count;
}

int get_index(char ch, char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == ch)
            return i;
    }
    return 0;
}

int **mem_alloc_2d_int(char *buffer, sand_t *sand)
{
    int **map = NULL;

    sand->sy = count_char(buffer, '\n');
    sand->sx = count_cols(buffer);
    map = calloc(sizeof(int *), (sand->sy));
    for (int i = 0; i < sand->sy; i++) {
        map[i] = calloc(sizeof(int), (sand->sx));
    }
    return map;
}

int **buff_to_int(char *buffer, char *str, sand_t *sand)
{
    int **map = mem_alloc_2d_int(buffer, sand);
    int index = 0;
    int j = 0;

    for (int i = 0; buffer[i] != 0; i++) {
        if (buffer[i] == '\n') {
            index = 0;
            j++;
            continue;
        }
        map[j][index] = get_index(buffer[i], str);
        index++;
    }
    return map;
}
