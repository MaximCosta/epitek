/*
** EPITECH PROJECT, 2021
** B-BOO-101-MPL-1-1-phoenixd02-maxim.costa [WSL: Ubuntu]
** File description:
** my_strcapitalize
*/

static char *lowcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (65 <= str[i] && str[i] <= 90)
            str[i] = str[i] + 32;
    return str;
}

char *my_strcapitalize(char *str)
{
    str = lowcase(str);
    if (97 <= str[0] && str[0] <= 122)
        str[0] = str[0] - 32;
    for (int i = 1; str[i]; i++)
        if (31 < str[i - 1] && str[i - 1] < 48 && 96 < str[i] && str[i] < 123)
            str[i] = str[i] - 32;
    return (str);
}