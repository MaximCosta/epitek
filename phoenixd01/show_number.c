/*
** EPITECH PROJECT, 2021
** B-BOO-101-MPL-1-1-phoenixd01-maxim.costa [WSL: Ubuntu]
** File description:
** show_number
*/

void my_putchar(char c);

static int my_putstr(char const* str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
    return 0;
}

int show_number(int nb)
{
    int nbr2;

    if (nb == -2147483648)
        return my_putstr("-2147483648");
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb >= 10) {
        show_number(nb / 10);
        my_putchar((nb % 10) + 48);
    } else {
        my_putchar(nb + 48);
    }
    return 0;
}
