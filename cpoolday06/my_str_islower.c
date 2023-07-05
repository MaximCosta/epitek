/*
** EPITECH PROJECT, 2021
** my_str_islower
** File description:
** islower
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (65 <= str[i] && str[i] <= 90)
            return 0;
        i++;
    }
    return 1;
}
