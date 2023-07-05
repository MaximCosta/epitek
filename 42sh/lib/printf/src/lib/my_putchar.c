/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** my_putchar.c
*/

#include "my_printf.h"

int my_putchar(char c)
{
    return write(1, &c, 1);
}

int my_putstr(char *s)
{
    return write(1, s, my_strlen(s));
}
