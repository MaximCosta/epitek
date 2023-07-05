/*
** EPITECH PROJECT, 2021
** my_ls [WSL: Ubuntu]
** File description:
** my_realloc
*/

#include <stdlib.h>

void *my_calloc(int type, int r, int size);

char *my_realloc(char *ptr, int size)
{
    char *ptr_realloc;

    if (ptr == NULL || size < 1)
        return (NULL);
    ptr_realloc = my_calloc(sizeof(char), '\0', size + 1);
    if (ptr_realloc == NULL)
        return (NULL);
    for (int c = 0; c != size && ptr[c] != '\0'; c++)
        ptr_realloc[c] = ptr[c];
    ptr_realloc[size] = '\0';
    free(ptr);
    return (ptr_realloc);
}
