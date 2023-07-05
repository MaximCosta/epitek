/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bspushswap-maxim.costa [WSL: Ubuntu]
** File description:
** test_bubble test bub
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void swap_elem(int *array, int index1, int index2);
void bubble_sort_array(int *array, int size);

Test(swap_elem, index1_greater_than_index2)
{
    int array[6] = {1, 2, 3, 4, 5, 6};
    int index1 = 2;
    int index2 = 4;
    swap_elem(array, index1, index2);
    cr_assert_eq(array[index1], 5);
    cr_assert_eq(array[index2], 3);
}

Test(bubble_sort_array, sort_array)
{
    int array1[6] = {6, 5, 4, 3, 2, 1};
    int array2[6] = {1, 2, 3, 4, 5, 6};
    bubble_sort_array(array1, 6);
    cr_assert_arr_eq(array1, array2, 6);
}