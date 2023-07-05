/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday06-kilyan.cotten
** File description:
** my_str_isprintable.c
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] < 32 || str[i] > 126)
            return 0;
        i++;
    }
    return 1;
}
