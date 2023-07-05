/*
** EPITECH PROJECT, 2021
** My_isneg
** File description:
** displays N or P
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    my_putchar('\n');
    return (0);
}
