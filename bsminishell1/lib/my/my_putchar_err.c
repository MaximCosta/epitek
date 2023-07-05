/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-maxim.costa
** File description:
** my_putchar_err
*/

#include <unistd.h>

void my_putchar_err(char c)
{
    write(2, &c, 1);
}
