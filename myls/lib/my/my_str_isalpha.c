/*
** EPITECH PROJECT, 2021
** my_str_isalpha
** File description:
** isalpha
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i]; i++)
        if ((str[i] < 65 || 90 < str[i]) && (str[i] < 97 || 122 < str[i]))
            return 0;
    return 1;
}
