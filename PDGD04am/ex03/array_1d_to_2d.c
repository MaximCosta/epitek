/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD04am-maxim.costa [WSL: Ubuntu]
** File description:
** array_1d_to_2d
*/

#include <stdio.h>
#include <stdlib.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    int i, j;
    int **array_2d = (int **) malloc(height * sizeof(int *));
    for (i = 0; i < height; i++) {
        array_2d[i] = (int *) malloc(width * sizeof(int));
        for (j = 0; j < width; j++) {
            array_2d[i][j] = array[i * width + j];
        }
    }
    *res = array_2d;
}

void array_2d_free(int **array, size_t height, size_t width)
{
    int i;
    for (i = 0; i < height; i++) {
        free(array[i]);
    }
    free(array);
}
