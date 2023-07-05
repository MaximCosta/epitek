/*
** EPITECH PROJECT, 2021
** test [SSH: 192.168.177.128]
** File description:
** my_strtol
*/

#include <stdlib.h>

long int my_strtol(char *s, char **endptr)
{
    long int lnb = 0;
    char c;

    for (; *s == ' '; s++);
    c = *s;
    if (c == '+' || c == '-')
        s++;
    for (; '0' <= *s && *s <= '9'; s++)
        lnb = lnb * 10 + *s - '0';
    if (endptr != NULL)
        *endptr = s;
    if (c == '-')
        lnb = -lnb;
    return lnb;
}
