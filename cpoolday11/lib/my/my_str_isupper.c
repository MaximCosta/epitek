/*
** EPITECH PROJECT, 2021
** my_str_isupper
** File description:
** return bool upper ?
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] >= 97 && str[i] <= 122)
            return 0;
        i++;
    }
    return 1;
}
