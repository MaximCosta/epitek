/*
** EPITECH PROJECT, 2021
** my_min_array
** File description:
** get min index
*/

int find_minimum(float a[], int n)
{
    int index = 0;
    int min = a[0];

    for (int c = 1; c < n; c++)
        if (a[c] < min)
            index = c;
    return index;
}
