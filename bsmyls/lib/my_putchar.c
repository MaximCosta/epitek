/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** write
*/

#include "my_printf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}