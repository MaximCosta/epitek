/*
** EPITECH PROJECT, 2021
** my_strcapitalize
** File description:
** Capitalize
*/

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str)
{
    int i = 1;

    str = my_strlowcase(str);
    if (97 <= str[0] && str[0] <= 122)
        str[0] = str[0] - 32;
    while (str[i] != '\0') {
        if (31 < str[i - 1] && str[i - 1] < 48 && 96 < str[i] && str[i] < 123)
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}
