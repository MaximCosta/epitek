/*
** EPITECH PROJECT, 2021
** my_swap_char
** File description:
** swap char
*/

void my_swap_char(char *a, char *b)
{
    char c = *a;

    *a = *b;
    *b = c;
}
