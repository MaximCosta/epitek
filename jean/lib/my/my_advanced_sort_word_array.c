/*
** EPITECH PROJECT, 2021
** Pool Day10
** File description:
** my_advanced_sort_word_array
*/

#include "my.h"

static void did_swap(char **w, int *f, int (*c)(char const *, char const *))
{
    if ((*c)(*w, *(w + 1)) > 0) {
        my_swap_string(w, w + 1);
        *f = 1;
    }
}

int my_advanced_sort_word_array(char **t, int (*c)(char const *, char const *))
{
    int nb_line = nbr_line_char_tab(t);
    char **begin = t;
    int find = 1;

    while (find) {
        find = 0;
        for (int i = 0; i < nb_line - 1; i++) {
            did_swap(t++, &find, c);
        }
        t = begin;
    }
    return (0);
}
