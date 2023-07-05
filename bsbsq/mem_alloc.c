/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-maxim.costa
** File description:
** mem_alloc
*/

#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);

char *mem_alloc(char const *a ,char const *b)
{
    int len = my_strlen(a) + my_strlen(b);
    char *c = malloc(sizeof(char) * (len + 1));

    c = my_strcpy(c, a);
    c = my_strcat(c, b);
    c[len] = '\0';
    return c;
}