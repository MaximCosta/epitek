/*
** EPITECH PROJECT, 2021
** my_putnbr_base
** File description:
** hey. real programmers use vim
*/

void my_putchar(char c);
int my_strlen(char const *str);

int my_putnbr_base(int nbr, char const *base)
{
    int si;

    if (nbr < 0) {
        my_putnbr_base(nbr * -1, base);
    } else if (nbr > 0) {
        si = my_strlen(base);
        my_putnbr_base(nbr / si, base);
        my_putchar(base[nbr % si]);
    }
}
