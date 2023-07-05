/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myftp-hades.cuisinier
** File description:
** my_strdup
*/

#include <stdlib.h>
#include <string.h>

char *my_strdup(char const *src)
{
    if (src == NULL)
        return NULL;
    char *dest = malloc(sizeof(char) * (strlen(src) + 1));
    int i = 0;

    if (dest == NULL)
        return NULL;
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
