/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** my put nbr
*/

void my_putchar(char c);
int my_strlen(char const *s);

int my_putnbr_base(int n, char const *base_tab)
{
    int base = my_strlen(base_tab);

    if (n < 0) {
        my_putchar('-');
        if (n / base)
            my_putnbr_base(-(n / base), base_tab);
        my_putchar(base_tab[-(n % base)]);
        return 0;
    }
    if (n) {
        if (n / base) {
            my_putnbr_base(n / base, base_tab);
        }
    }
    my_putchar(base_tab[n % base]);
    return 0;
}
