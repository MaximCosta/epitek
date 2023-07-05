/*
** EPITECH PROJECT, 2022
** tetris [WSL: Ubuntu]
** File description:
** lib1
*/

#include "../include/tetris.h"

void my_exit(int code, char *error)
{
    write(2, error, my_strlen(error));
    write(2, "\n", 1);
    exit(code);
}

void *my_calloc(size_t size1, size_t size2)
{
    void *ptr = malloc(size1 * size2);

    if (ptr == NULL)
        my_exit(84, "Error: malloc failed\n");
    for (size_t i = 0; i < size1 * size2; i++)
        ((char *) ptr)[i] = 0;
    return (ptr);
}

void **my_calloc2d(int height)
{
    void **array = malloc(sizeof(void *) * height);
    int i = 0;

    for (; i < height; i++)
        array[i] = NULL;
    return array;
}

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {};
    return (i);
}

char *my_strcat(char *dest, char *src)
{
    char *str = my_calloc(sizeof(char), my_strlen(dest) + my_strlen(src) + 1);
    int i = 0;
    int j = 0;

    for (; dest[i] != '\0'; str[i++] = dest[i]) {};
    for (; src[j] != '\0'; str[i++] = src[j++]) {};
    return (str);
}
