/*
** EPITECH PROJECT, 2021
** Pool Day09
** File description:
** swap_endian_color
*/

#include "my.h"

int swap_endian_color(int color)
{
    union endian {
        int entier;
        unsigned char byte[4];
    };
    union endian clr = {0};
    short int test = 0x0001;
    char *type_endian = (char *) & test;

    clr.entier = color;
    my_swap_unsigned_char(&clr.byte[0], &clr.byte[3]);
    my_swap_unsigned_char(&clr.byte[1], &clr.byte[2]);
    return (type_endian[0] ? clr.entier : color);
}
