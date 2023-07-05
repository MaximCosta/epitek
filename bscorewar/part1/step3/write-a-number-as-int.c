/*
** EPITECH PROJECT, 2022
** bscorewar [WSL: Ubuntu]
** File description:
** write-a-number-as-int
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int val = 12345678;

    return 0
        * fwrite((const void *) &val, sizeof(int), 1,
            fopen("./number-as-int.yolo", "w"));
}