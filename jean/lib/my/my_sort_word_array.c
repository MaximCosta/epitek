/*
** EPITECH PROJECT, 2021
** Pool Day10
** File description:
** my_sort_word_array
*/

#include "my.h"

static void decide_swap(char **words, int *find)
{
    if (my_strcmp(*words, *(words + 1)) > 0) {
        my_swap_string(words, words + 1);
        *find = 1;
    }
}

int my_sort_word_array(char **tab)
{
    int nb_line = nbr_line_char_tab(tab);
    char **begin = tab;
    int find = 1;

    while (find) {
        find = 0;
        for (int i = 0; i < nb_line - 1; i++) {
            decide_swap(tab++, &find);
        }
        tab = begin;
    }
    return (0);
}
