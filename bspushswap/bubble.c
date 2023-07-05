/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bspushswap-maxim.costa [WSL: Ubuntu]
** File description:
** bubble test bub
*/

void swap_elem(int *array, int index1, int index2)
{
    int tmp = array[index1];

    array[index1] = array[index2];
    array[index2] = tmp;
}

void bubble_sort_array(int *array, int size)
{
    int i = 1;

    while (i < size) {
        if (array[i-1] > array[i]) {
            swap_elem(array, i-1, i);
            i = 0;
        }
        i++;
    }
}