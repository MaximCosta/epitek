/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** My_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    char *begin = dest;

    while (*src != '\0' && n > 0) {
        *dest++ = *src++;
        n--;
    }
    for (int i = n; i > 0; i--) {
        *dest++ = '\0';
    }
    return (begin);
}
