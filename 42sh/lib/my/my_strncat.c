/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday07-kilyan.cotten
** File description:
** my_strncat.c
*/

int my_strlen(char const *s);

char *my_strncat(char *dest , char const *src, int n)
{
    int i = 0;
    int len = my_strlen(dest);

    while (src[i] && i < n) {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = 0;
    return dest;
}
