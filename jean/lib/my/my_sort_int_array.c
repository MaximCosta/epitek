/*
** EPITECH PROJECT, 2021
** Pool Day04
** File description:
** My_sort_int_array
*/

#include "my.h"

static void decide_swap(int *n, int *find)
{
    if (*n > *(n + 1)) {
        my_swap(n, n + 1);
        *find = 1;
    }
}

void my_sort_int_array(int *array, int size)
{
    int find = 1;
    int *p_find = &find;
    int *begin = array;

    while (find) {
        find = 0;
        for (int i = 0; i < size - 1; i++) {
            decide_swap(array++, p_find);
        }
        array = begin;
    }
}
