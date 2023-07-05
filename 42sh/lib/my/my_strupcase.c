/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday06-kilyan.cotten
** File description:
** my_strupcase.c
*/

int is_lower(char c);

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i]) {
        if (is_lower(str[i]))
            str[i] -= 32;
        i++;
    }
    return str;
}
