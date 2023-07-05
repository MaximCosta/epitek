/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** my_putnbr_str
*/

static int putnbr_str_rec(int nb, char *str, int i)
{
    if (nb != 0) {
        i = putnbr_str_rec(nb / 10, str, i);
        str[i] = '0' + (nb % 10);
    }
    return (i + 1);
}

int my_putnbr_str(int nb, char *str)
{
    int i = -1;

    if (nb < 0) {
        str[i + 1] = '-';
        i = putnbr_str_rec(-nb / 10, str, i + 1);
        str[i] = ('0' + (-nb % 10));
        i++;
    } else if (nb > 0)
        i = putnbr_str_rec(nb, str, i);
    else
        str[0] = '0';
    return i;
}
