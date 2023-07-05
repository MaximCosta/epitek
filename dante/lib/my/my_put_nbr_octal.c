/*
** EPITECH PROJECT, 2021
** Myputnbr
** File description:
** prints numbers
*/

void my_putchar(char c);

void my_putstr(char const *str);

int my_put_nbr_octal(int nb)
{
    if (nb < 0)
        return 0;
    if (nb > 9) {
        my_put_nbr_octal(nb / 10);
        my_put_nbr_octal(nb % 10);
    } else
        my_putchar('0' + nb);
    return 0;
}
