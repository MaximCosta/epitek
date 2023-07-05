/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-maxim.costa
** File description:
** array_2d_how_many
*/

int array_2d_how_many(int **arr, int nb_rows, int nb_cols, int number)
{
    int res = 0;

    for (int y = 0; y < nb_rows; y++)
        for (int x = 0; x < nb_cols; x++)
            arr[y][x] == number && res++;
    return res;
}