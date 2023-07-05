/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-maxim.costa
** File description:
** mem_dup_2d_array
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src);

char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols)
{
    char **str;

    if (!(str = malloc(sizeof(char *) * nb_rows))) return NULL;
    for (int i = 0; i < nb_rows; i++) {
        if (!(str[i] = malloc(nb_cols))) return NULL;
        str[i] = my_strcpy(str[i], arr[i]);
    }
    return str;
}