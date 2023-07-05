/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday06-kilyan.cotten
** File description:
** my_str_islower.c
*/

int is_lower(char c);

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (!is_lower(str[i]))
            return 0;
        i++;
    }
    return 1;
}
