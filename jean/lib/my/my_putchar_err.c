/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** my_putchar_err
*/

#include <unistd.h>

void my_putchar_err(char c)
{
    write(2, &c, 1);
}
