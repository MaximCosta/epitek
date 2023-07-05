/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** put every letter in uppercase
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i]) {
        if (97 <= str[i] && str[i] <= 122)
            str[i] = str[i] - 32;
        i++;
    }
    return str;
}
