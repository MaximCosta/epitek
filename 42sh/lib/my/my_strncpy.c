/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday06-kilyan.cotten
** File description:
** my_strncpy.c
*/

char *my_strncpy(char *dest , char const *src , int n)
{
    int i = 0;

    while (i < n && src[i]) {
        dest[i] = src[i];
        i++;
    }
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return dest;
}
