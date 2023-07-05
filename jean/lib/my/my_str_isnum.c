/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** my_str_isnum
*/

static int is_digit(char c)
{
    if (c > 47 && c < 58)
        return (1);
    return (0);
}

int my_str_isnum(char const *str)
{
    while (*str != '\0') {
        if (!is_digit(*str))
            return (0);
        str++;
    }
    return (1);
}
