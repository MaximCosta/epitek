/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-bsmyprintf-maxim.costa
** File description:
** my_putchar
*/

#include <unistd.h>
#include "bsprintf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}