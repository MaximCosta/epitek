/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** Write a function for print the number given as a parameter.
*/

void my_putchar(char c);
int my_putstr(char const *str);

int my_put_nbr(int nb)
{
    int nbr2;

    if (nb == -2147483648)
        return my_putstr("-2147483648");
    if (nb < 0) {
        my_putchar('-');
        nb *= (-1);
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    } else {
        my_putchar(nb + 48);
    }
    return 0;
}
