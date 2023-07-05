/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday06-kilyan.cotten
** File description:
** my_strstr.c
*/

#include <stdio.h>

char *my_strstr(char *str , char const *to_find)
{
    int i = 0;
    int j = 0;

    while (str[i]) {
        if (to_find[j] == '\0')
            return str + i - j;
        if (str[i] == to_find[j]) {
            j++;
            i++;
            continue;
        }
        if (str[i] != to_find[j] && j)
            i--;
        j = 0;
        i++;
    }
    if (to_find[j] == '\0')
        return str + i - j;
    return 0;
}
