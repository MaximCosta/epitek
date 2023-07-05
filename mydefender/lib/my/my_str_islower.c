/*
** EPITECH PROJECT, 2021
** my_str_islower
** File description:
** islower
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] < 97 || 122 < str[i])
            return 0;
        i++;
    }
    return 1;
}
