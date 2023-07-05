/*
** EPITECH PROJECT, 2021
** Myputnbr
** File description:
** prints numbers
*/

void my_putchar(char c);

void my_putstr(char const *str);

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return 0;
    }
    if (nb < 0) {
        my_putchar('-');
        nb *= (-1);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else
        my_putchar('0' + nb);
    return 0;
}
