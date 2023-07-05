/*
** EPITECH PROJECT, 2021
** my_str_isnum
** File description:
** is num
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] < 48 || 57 < str[i])
            return 0;
        i++;
    }
    return 1;
}
