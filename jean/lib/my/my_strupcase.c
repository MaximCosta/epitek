/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** my_strupcase
*/

char *my_strupcase(char *str)
{
    char *begin = str;

    while (*str != '\0') {
        if (*str > 96 && *str < 123) {
            *str -= 32;
        }
        str++;
    }
    return (begin);
}
