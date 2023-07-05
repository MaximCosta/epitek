/*
** EPITECH PROJECT, 2021
** my_putnbr_base
** File description:
** Convert Decimal
*/

void my_putchar(char c);

int string_length(char const *s)
{
    int c = 0;

    while (s[c] != '\0')
        c++;
    return c;
}

int display_convert(int nbr, char const* base, int size_base)
{
    if (nbr >= size_base) {
        display_convert(nbr / size_base, base, size_base);
        my_putchar(base[nbr % size_base]);
    } else {
        my_putchar(base[nbr % size_base]);
    }
}

int my_putnbr_base(int nbr, char const* base)
{
    int size_base = 1;
    size_base = string_length(base);
    if (size_base != 0)
        display_convert(nbr, base, size_base);
    return 0;
}
