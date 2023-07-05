/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** my_swap day 4
*/

void my_swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
