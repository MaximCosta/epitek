/*
** EPITECH PROJECT, 2021
** my_calloc
** File description:
** xkcd.com/378
*/

#include <stdlib.h>

static void *my_setmem(void *s, int c, int l)
{
    char *tmp = s;

    for (int i = 0; i < l; i++)
        tmp[i] = c;
    return s;
}

void *my_calloc(int type, int r, int size)
{
    void *ptr = malloc(type * size);

    if (!ptr) {
        return NULL;
    }
    return my_setmem(ptr, r, size);
}
