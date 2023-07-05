/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday07-kilyan.cotten
** File description:
** my_strcat.c
*/

int my_strlen(char const *s);
#include <stdio.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(dest);

    while (src[i]) {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = 0;
    return dest;
}
