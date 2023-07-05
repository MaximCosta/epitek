/*
** EPITECH PROJECT, 2021
** Day08
** File description:
** Task01 - MY_STRDUP
*/

#include "../../include/common.h"

int is_little_endian(void)
{
    short int n = 0x1;
    char *np = (char *) &n;
    return np[0] == 0x1;
}

long long int little_to_big_endian(long long int x)
{
    if (!is_little_endian())
        return x;
    return ((x & 0x000000FF) << 24) | ((x & 0x0000FF00) << 8)
        | ((x & 0x00FF0000) >> 8) | ((x & 0xFF000000) >> 24);
}

long long int swap_int32(long long int n)
{
    n = ((n << 8) & 0xFF00FF00) | ((n >> 8) & 0xFF00FF);
    return (n << 16) | ((n >> 16) & 0xFFFF);
}
