/*
** EPITECH PROJECT, 2021
** Day08
** File description:
** Task01 - MY_STRDUP
*/

#include "../../include/common.h"

int bin_to_dec(char *bytes)
{
    int x = 0;
    int final_byte = 0;

    do {
        x = *bytes == '1' ? 1 : 0;
        final_byte = (final_byte << 1) | x;
        bytes++;
    } while (*bytes);
    return final_byte;
}
