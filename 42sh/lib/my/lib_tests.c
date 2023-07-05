/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday06-kilyan.cotten
** File description:
** lib_tests.c
*/

#include <stdbool.h>

int is_letter(char c)
{
    return (c >= 65 && c <= 90) || (c >= 97 && c <= 122) ? 1 : 0;
}

int is_lower(char c)
{
    return c >= 97 && c <= 122 ? 1 : 0;
}

int is_number(char c)
{
    return c >= 48 && c <= 57 ? 1 : 0;
}

bool is_special(char c)
{
    return c == '_' ? true : false;
}
