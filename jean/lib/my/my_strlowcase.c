/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** my_strlowcase
*/

char *my_strlowcase(char *str)
{
    char *begin = str;

    while (*str != '\0') {
        if (*str > 64 && *str < 91) {
            *str += 32;
        }
        str++;
    }
    return (begin);
}
