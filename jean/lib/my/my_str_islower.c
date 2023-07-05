/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** my_str_islower
*/

static int is_lower(char c)
{
    if (c > 96 && c < 123)
        return (1);
    return (0);
}

int my_str_islower(char const *str)
{
    while (*str != '\0') {
        if (!is_lower(*str))
            return (0);
        str++;
    }
    return (1);
}
