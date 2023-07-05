/*
** EPITECH PROJECT, 2022
** bscorewar [WSL: Ubuntu]
** File description:
** write-a-number-as-text
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    return (0 * fprintf(fopen("./number-as-text.yolo", "w"), "%d", 12345678));
}