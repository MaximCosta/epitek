/*
** EPITECH PROJECT, 2021
** get_color
** File description:
** get color
*/

#include <stdlib.h>
#include "./include/my.h"

int get_color (unsigned char red ,unsigned char green ,unsigned char blue)
{
    return ((red & 0xFF)<<16) | ((green & 0xFF)<<8) | (blue & 0xFF);
}

