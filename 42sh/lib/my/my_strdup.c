/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday08-kilyan.cotten
** File description:
**  my_strdup.c
*/

#include <stdlib.h>
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *str);

char *my_strdup(char const *str)
{
    int len = my_strlen(str);
    char *dest = malloc(sizeof(char) * (len + 1));

    my_strcpy(dest, str);
    dest[len] = 0;
    return dest;
}
