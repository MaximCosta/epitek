/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** my_swap_unsigned_char
*/

void my_swap_unsigned_char(unsigned char *a, unsigned char *b)
{
    unsigned char c = *a;

    *a = *b;
    *b = c;
}
