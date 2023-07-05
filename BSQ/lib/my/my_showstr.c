/*
** EPITECH PROJECT, 2021
** my_showstr
** File description:
** epitech > epita
*/

int my_putnbr_base(int nbr, char const *base);
void my_putchar(char c);

static void zero_print(char s)
{
    if (s <= 16)
        my_putchar('0');
}

int my_showstr(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < 32) {
            my_putchar('\\');
            zero_print(str[i]);
            my_putnbr_base((int)str[i], "0123456789abcdef");
        } else {
            my_putchar(str[i]);
        }
    }
    return 0;
}
