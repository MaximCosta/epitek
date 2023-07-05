/*
** EPITECH PROJECT, 2021
** B-BOO-101-MPL-1-1-phoenixd02-maxim.costa [WSL: Ubuntu]
** File description:
** my_strupcase
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (97 <= str[i] && str[i] <= 122)
            str[i] = str[i] - 32;
    return str;
}