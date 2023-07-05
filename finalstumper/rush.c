/*
** EPITECH PROJECT, 2021
** rush_square
** File description:
** Write square
*/

#include <unistd.h>
#include "include/my.h"

void my_puta(char c, char *putr, int *s)
{
    putr[*s] = c;
    (*s)++;
}

int angle_print(int *argc, int *argw, char *putr)
{
    int x1 = argc[0];
    int y1 = argc[1];
    int x = argc[2];
    int y = argc[3];
    int active = argw[0];
    int sqa[4][3] = {
        { 0, 0, argw[1] },
        { 0, x, argw[2] },
        { y, 0, argw[3] },
        { y, x, argw[4] }
    };

    for (int i = 0; i < 4; i++) {
        if (y1 == sqa[i][0] && x1 == sqa[i][1]) {
            my_puta(sqa[i][2], putr, &argw[7]);
            return 1;
        }
    }
    return 0;
}

int square_print(int *argc, int *argw, char *putr)
{
    int x1 = argc[0];
    int y1 = argc[1];
    int x = argc[2];
    int y = argc[3];
    int active = argw[0];

    if (active || (y != 0 && x != 0))
        if (angle_print(argc, argw, putr))
            return 0;
    if (y1 == 0 || y1 == y) {
        my_puta(argw[5], putr, &argw[7]);
        return 0;
    }
    if (x1 == 0 || x1 == x) {
        my_puta(argw[6], putr, &argw[7]);
        return 0;
    }
    my_puta(' ', putr, &argw[7]);
    return 0;
}

void rush(int x, int y, int *argw, char *putr)
{
    int argc[4] = { 0, 0, x - 1, y - 1 };

    for (argc[1] = 0; argc[1] < y; argc[1]++) {
        for (argc[0] = 0; argc[0] < x; argc[0]++) {
            square_print(argc, argw, putr);
        }
        my_puta('\n', putr, &argw[7]);
    }
    my_puta('\0', putr, &argw[7]);
}
