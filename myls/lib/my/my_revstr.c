/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** revers string
*/

char *my_revstr(char *str)
{
    int i1 = 0;
    int i2 = 0;
    char *t = str;
    char tmp;

    while (str[i1] != '\0')
        i1++;
    for (i1--; i1 > i2; i1--, i2++) {
        tmp = t[i2];
        str[i2] = t[i1];
        str[i1] = tmp;
    }
    return str;
}
