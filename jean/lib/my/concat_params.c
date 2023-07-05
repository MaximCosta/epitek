/*
** EPITECH PROJECT, 2021
** Pool Day08
** File description:
** concat_params
*/

#include <stdlib.h>
#include "my.h"

char *concat_params(int argc, char **argv)
{
    char *dest;
    char *begin;
    int len = 0;

    for (int i = 0; i < argc; i++) {
        len = len + my_strlen(argv[i]) + 1;
    }
    dest = malloc(sizeof(char) * len);
    begin = dest;
    for (int i = 0; i < argc; i++) {
        while (*argv[i]) {
            *dest++ = *argv[i]++;
        }
        *dest++ = '\n';
    }
    *(--dest) = '\0';
    return begin;
}
