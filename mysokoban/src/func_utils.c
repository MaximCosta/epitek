/*
** EPITECH PROJECT, 2022
** sokoban [WSL: Ubuntu]
** File description:
** func_utils
*/

#include "my.h"

static void *my_setmem(void *s, int c, int l)
{
    char *tmp = s;

    for (int i = 0; i < l; tmp[i++] = c) {};
    return s;
}

void *my_calloc(int type, int r, int size)
{
    void *ptr = malloc(type * size);

    if (!ptr)
        return NULL;
    return my_setmem(ptr, r, size);
}

void **my_calloc_2d(int type, int size)
{
    void **ptr = malloc(type * size);

    if (!ptr)
        return NULL;
    for (int i = 0; i < size; ptr[i++] = NULL) {};
    return ptr;
}

void check_chr(char c)
{
    char check[7] = "#XPO \n\0";

    for (int i = 0; i < 7; i++)
        if (c == check[i])
            return;
    exit(EXIT_FAILURE);
}

void countlines(char *filename, game_t *game)
{
    FILE *fp = fopen(filename, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (fp == NULL)
        exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, fp)) != -1) {
        for (int j = 0; j < len; j++) {
            check_chr(line[j]);
            game->box += line[j] && line[j] == 'X' ? 1 : 0;
        }
        game->h++;
    }
    fclose(fp);
}
