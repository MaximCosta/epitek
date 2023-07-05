/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** My_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    char *begin = dest;

    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
    return (begin);
}
