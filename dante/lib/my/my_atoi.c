/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-BSQ-hades.cuisinier
** File description:
** my_atoi
*/

#include <stdbool.h>
#include <stdio.h>

bool is_number(char c);

int my_atoi(char *str)
{
    int nbr = 0;
    char *ptr = str;

    while (is_number(*ptr)) {
        nbr = nbr * 10 + *ptr - '0';
        ptr += 1;
    }
    return nbr;
}
