/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** utils_func
*/

#include "my_printf.h"

int my_showstr_octal(char *buf)
{
    for (int i = 0; buf[i]; i++) {
        if (buf[i] >= 32 && buf[i] <= 126)
            my_putchar(buf[i]);
        else
            nbr_octal_print(convert_octal(buf[i]));
    }
    return 0;
}

void nbr_octal_print(int oct)
{
    my_putchar('\\');
    for (int i = 1; oct * i < 100; i *= 10)
        my_putchar('0');
    my_put_nbr(oct);
}

int convert_octal(int dec)
{
    int oct = 0;
    for (int i = 1; dec; dec /= 8, i *= 10)
        oct += (dec % 8) * i;
    return oct;
}