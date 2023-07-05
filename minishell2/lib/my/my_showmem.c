/*
** EPITECH PROJECT, 2021
** my_showmem
** File description:
** xkcd.com/378
*/

void my_putchar(char c);
void my_putstr(char const *str);
int my_putnbr_base(int nbr, char const *base);

static int count_in_base(int nbr)
{
    if (nbr < 0) {
        return count_in_base(nbr * -1);
    } else if (nbr > 0) {
        return 1 + count_in_base(nbr / 16);
    }
    return 0;
}

static void show_hex(char c, int i, int k, int size)
{
    if (i + k > size) {
        my_putstr("  ");
    } else {
        if (c == 0)
            my_putchar('0');
        if (-15 <= c && c <= 15)
            my_putchar('0');
        my_putnbr_base(c, "0123456789abcdef");
    }
    if (i % 2 == 1)
        my_putchar(' ');
}

static void show_str(char c, int i, int si)
{
    if (c < 32 && i < si)
        my_putchar('.');
    else if (i < si)
        my_putchar(c);
}

static void show_addr(int val)
{
    int count = count_in_base(val);

    for (int i = 0; i < 8 - count; i++) {
        my_putchar('0');
    }
    my_putnbr_base(val, "0123456789abcdef");
    my_putstr(": ");
}

int my_showmem(char const *str, int size)
{
    for (int k = 0; k < size; k += 16) {
        show_addr(k);
        for (int i = 0; i < 16; i++)
            show_hex(str[k + i], i, k, size);
        for (int i = 0; i < 16; i++)
            show_str(str[k + i], k + i, size);
        my_putchar('\n');
    }
    return 0;
}
