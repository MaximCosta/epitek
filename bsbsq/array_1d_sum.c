/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-maxim.costa
** File description:
** array_1d_sum
*/

int array_1d_sum(int const *arr, int size)
{
    int res = 0;

    for (int i = 0; i < size; i++)
        res += arr[i];
    return res;
}