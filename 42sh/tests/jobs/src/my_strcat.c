/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** my_strcat
*/

#include "../include/jobs.h"

static char *cpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *strcat_alloc(char *dest, char *src)
{
    int i = 0;
    int dest_len = my_strlen(dest);
    char *res = malloc(dest_len + my_strlen(src) + 1);

    cpy(res, dest);
    while (src[i]) {
        res[dest_len + i] = src[i];
        i++;
    }
    res[dest_len + i] = 0;
    return res;
}
