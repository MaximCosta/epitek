/*
** EPITECH PROJECT, 2021
** Pool Day07
** File description:
** my_strncat
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    char *begin = dest;

    while (*dest) {
        dest++;
    }
    while (*src && nb > 0) {
        *dest++ = *src++;
        nb--;
    }
    *dest = '\0';
    return begin;
}
