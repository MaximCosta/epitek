/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday06-kilyan.cotten
** File description:
** my_strlowcase.c
*/

int is_lower(char c);
int is_letter(char c);

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i]) {
        if (!is_lower(str[i]) && is_letter(str[i]))
            str[i] += 32;
        i++;
    }
    return str;
}
