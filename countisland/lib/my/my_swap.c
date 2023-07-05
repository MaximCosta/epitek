/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** swap to int swap
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
