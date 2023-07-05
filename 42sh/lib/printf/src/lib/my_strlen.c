/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** my_strlen.c
*/

#include "my_printf.h"

int my_strlen(char const *s)
{
    int len = 0;

    for (len = 0; s[len]; len++);
    return len;
}
