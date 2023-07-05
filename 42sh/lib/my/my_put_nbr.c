/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** my put nbr
*/

void my_putchar(char c);

int my_put_nbr(int n)
{
    if (n < 0) {
        my_putchar('-');
        if (n / 10)
            my_put_nbr(-(n / 10));
        my_putchar(-(n % 10) + 48);
        return 0;
    }
    if (n) {
        if (n / 10) {
            my_put_nbr(n / 10);
        }
    }
    my_putchar(n % 10 + 48);
    return 0;
}
