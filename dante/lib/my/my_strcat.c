/*
** EPITECH PROJECT, 2021
** day07 task02
** File description:
** that concatenates two strings
*/

char *my_strcat(char *dest, char *str)
{
    int i = 0;
    int j = 0;

    while (dest[i])
        i++;
    while (str[j]) {
        dest[i] = str[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}
