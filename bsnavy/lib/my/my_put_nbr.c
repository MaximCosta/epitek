/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** Write a function for print the number given as a parameter.
*/

void my_putchar(char c);

static int my_min_int(char const* str)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
    return 0;
}

int my_put_nbr(int nb)
{
    int nbr2;

    if (nb == -2147483648) {
        my_min_int("-2147483648");
        return 0;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10) {
        nbr2 = nb % 10;
        nb /= 10;
        my_put_nbr(nb);
        my_putchar(nbr2 + 48);
    } else {
        my_putchar(nb + 48);
    }
    return 0;
}
