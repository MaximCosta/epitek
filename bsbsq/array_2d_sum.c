/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-maxim.costa
** File description:
** array_2d_sum
*/

int array_2d_sum(int **arr, int nb_rows, int nb_cols)
{
    int res = 0;

    for (int y = 0; y < nb_rows; y++)
        for (int x = 0; x < nb_cols; x++)
            res += arr[y][x];
    return res;
}