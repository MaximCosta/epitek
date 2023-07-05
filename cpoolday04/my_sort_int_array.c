/*
** EPITECH PROJECT, 2021
** my_sort_int_array
** File description:
** sort array in c
*/

void my_swap(int *a, int *b);

void bub_check(int *arr, int j)
{
    if (arr[j] > arr[j + 1])
        my_swap(&arr[j], &arr[j + 1]);
}

void my_sort_int_array(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            bub_check(arr, j);
}
