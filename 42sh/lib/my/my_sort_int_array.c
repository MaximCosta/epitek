/*
** EPITECH PROJECT, 2021
** my_sort_int_array.c
** File description:
** my_sortintarray
*/

void my_swap(int *a, int *b);

static void test_same(int *val1, int *val2)
{
    if (*val1 > *val2) {
        my_swap(val1, val2);
    }
}

void my_sort_int_array(int *array, int size)
{
    int i;
    int j;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            test_same(array + j, array + j + 1);
        }
    }
}
