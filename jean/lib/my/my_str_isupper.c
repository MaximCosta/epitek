/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** my_str_isupper
*/

static int is_upper(char c)
{
    if (c > 64 && c < 91) {
        return (1);
    }
    return (0);
}

int my_str_isupper(char const *str)
{
    while (*str != '\0') {
        if (!is_upper(*str)) {
            return (0);
        }
        str++;
    }
    return (1);
}
