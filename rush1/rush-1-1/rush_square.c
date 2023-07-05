/*
** EPITECH PROJECT, 2021
** rush_square
** File description:
** Write square
*/

#include <unistd.h>

void my_putchar(char c);

int angle_print(int *argc, int *argw)
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
            my_putchar(sqa[i][2]);
            return 1;
        }
    }
    return 0;
}

int square_print(int *argc, int *argw)
{
    int x1 = argc[0];
    int y1 = argc[1];
    int x = argc[2];
    int y = argc[3];
    int active = argw[0];

    if (active || (y != 0 && x != 0))
        if (angle_print(argc, argw))
            return 0;
    if (y1 == 0 || y1 == y) {
        my_putchar(argw[5]);
        return 0;
    }
    if (x1 == 0 || x1 == x) {
        my_putchar(argw[6]);
        return 0;
    }
    my_putchar(' ');
    return 0;
}

int rush(int x, int y)
{
    int argc[4] = { 0, 0, x - 1, y - 1 };
    int argw[7] = { 1, 111, 111, 111, 111, 45, 124 };

    if (x <= 0 || y <= 0) {
        write(2, "Invalid size\n", 13);
        return -1;
    }
    for (argc[1] = 0; argc[1] < y; argc[1]++) {
        for (argc[0] = 0; argc[0] < x; argc[0]++) {
            square_print(argc, argw);
        }
        my_putchar('\n');
    }
    return 0;
}
