/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday06-kilyan.cotten
** File description:
** my_str_isnum.c
*/

int is_number(char c);

int my_str_isnum(char const *str)
{
    int i = 0;

    if (*str == '-')
        str++;
    while (str[i]) {
        if (!is_number(str[i]))
            return 0;
        i++;
    }
    return 1;
}
