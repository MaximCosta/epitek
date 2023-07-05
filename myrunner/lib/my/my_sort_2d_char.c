/*
** EPITECH PROJECT, 2021
** my_ls [WSL: Ubuntu]
** File description:
** my_sort_2d_char
*/

#include <stdlib.h>

void my_strswap(char **str1, char **str2);
int my_strcmp(char const *s1, char const *s2);

void my_sort_2d(char **arr)
{
    int i = 1;

    while (arr[i] != NULL) {
        if (my_strcmp(arr[i-1], arr[i]) > 0) {
            my_strswap(&arr[i], &arr[i - 1]);
            i = 1;
        }
        i++;
    }
}
