/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** my_str_isalpha
*/

static int is_capitale_letter(char c)
{
    if (c > 64 && c < 91)
        return (1);
    return (0);
}

static int is_small_letter(char c)
{
    if (c > 96 && c < 123)
        return (1);
    return (0);
}

int my_str_isalpha(char const *str)
{
    while (*str != '\0') {
        if (!is_capitale_letter(*str) && !is_small_letter(*str))
            return (0);
        str++;
    }
    return (1);
}
