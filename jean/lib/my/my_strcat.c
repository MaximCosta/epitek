/*
** EPITECH PROJECT, 2021
** Pool Day07
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char const *src)
{
    char *begin = dest;

    while (*dest) {
        dest++;
    };
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
    return begin;
}
