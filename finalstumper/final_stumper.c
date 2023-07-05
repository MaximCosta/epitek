/*
** EPITECH PROJECT, 2021
** main
** File description:
** echo $?
*/

#include "include/my.h"
#include "rush3.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int argw[5][8] = {
    { 1, 111, 111, 111, 111, 45, 124, 0 },
    { 0, 47, 92, 92, 47, 42, 42, 0 },
    { 0, 65, 65, 67, 67, 66, 66, 0 },
    { 0, 65, 67, 65, 67, 66, 66, 0 },
    { 0, 65, 67, 67, 65, 66, 66, 0 }
};

void rush(int x, int y, int *argw, char *putr);

void my_cus_print(int rush, int x, int y)
{
    my_putstr("[rush1-");
    my_putchar(rush + '0');
    my_putchar(']');
    my_putchar(' ');
    my_put_nbr(x);
    my_putchar(' ');
    my_put_nbr(y);
}

void my_cus_strlen(char *str, int *x, int *y)
{
    int i = 0;

    while (str[*x] != '\n' && str[*x] != '\0') {
        (*x)++;
    }
    while (str[i] != '\0') {
        if (str[i] == '\n')
            (*y)++;
        i++;
    }
}

void rush3(char *buff)
{
    int y = 0;
    int x = 0;
    int r = 0;
    char *r1 = NULL;

    my_cus_strlen(buff, &x, &y);
    for (int i = 0; i < 5; i++) {
        r1 = malloc(sizeof(char) * ((x + 1) * y) + 1);
        rush(x, y, argw[i], r1);
        if (my_strcmp(r1, buff) == 0) {
            (r != 0) ? my_putstr(" || ") : 0;
            my_cus_print(i + 1, x, y);
            r++;
        }
        free(r1);
    }
    (r == 0) ? my_putstr("none") : 0;
    my_putchar('\n');
}

int main(void)
{
    char buff[BUFF_SIZE + 1];
    int offset = 0;
    int len;

    while ((len = read(0, buff + offset, BUFF_SIZE - offset)) > 0) {
        offset = offset + len;
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84);
    if (offset <= 1) {
        my_putstr("none\n");
        return 0;
    }
    rush3(buff);
    return (0);
}
