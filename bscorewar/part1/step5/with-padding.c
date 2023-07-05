/*
** EPITECH PROJECT, 2022
** bscorewar [WSL: Ubuntu]
** File description:
** with-padding
*/

#include <stdio.h>

typedef struct {
    int val;
    char c;
    char str[40];
} momo;

int main(int ac, char **av)
{
    momo m = {192837, 'k', "Corewar is swag!!"};
    return (0
        * fwrite((const void *) &m, sizeof(momo), 1,
            fopen("./one-structure.yolo", "w")));
}