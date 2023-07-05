/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** my_strcapitalize
*/

static char capitalize(char c)
{
    if (c > 96 && c < 123)
        return (c - 32);
    return c;
}

static char uncapitalize(char c)
{
    if (c > 64 && c < 91)
        return (c + 32);
    return c;
}

static void cast_sup(char *str, char c)
{
    if (*(str - 1) == c)
        *str = capitalize(*str);
}

static void cast_inf(char *str, char c[3])
{
    for (int i = 0; i < 3; i++) {
        if (*(str - 1) == c[i])
            return;
    }
    *str = uncapitalize(*str);
}

char *my_strcapitalize(char *str)
{
    char *begin = str;
    char c[3] = {' ', '+', '-'};

    if (*str > 96 && *str < 123) {
        *str -= 32;
    }
    str++;
    while (*str != '\0') {
        for (int i = 0; i < 3; i++) {
            cast_sup(str, c[i]);
        }
        cast_inf(str, c);
        str++;
    }
    return (begin);
}
