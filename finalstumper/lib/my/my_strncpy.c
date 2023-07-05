/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** copy n char to other
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; ++i) {
        dest[i] = src[i];
    }
    return dest;
}
