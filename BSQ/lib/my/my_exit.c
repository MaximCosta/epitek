/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-BSQ-maxim.costa [WSL: Ubuntu]
** File description:
** my_exit
*/

#include <stdlib.h>

int my_putstr_err(char const *str);

void my_exit(int code, char *msg)
{
    my_putstr_err(msg);
    exit(code);
}
