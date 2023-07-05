/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-hades.cuisinier
** File description:
** my_put_octal
*/

#include <stdio.h>

int my_put_nbr_octal(int nb);

unsigned int my_put_octal(unsigned int n)
{
    int counter = 1;
    int res = 0;

    while (n != 0) {
        res += (n % 8) * counter;
        n /= 8;
        counter *= 10;
    }
    my_put_nbr_octal(res);
    return 0;
}
