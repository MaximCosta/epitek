/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday06-kilyan.cotten
** File description:
** my_showstr.c
*/

void my_putchar(char c);
void my_putnbr_base(int n, char const *b);

static void print_no_printable(char c)
{
    my_putchar('\\');
    if (!(c / 16))
        my_putchar('0');
    my_putnbr_base(c, "0123456789abcdef");
}

int my_showstr(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] < 32 || str[i] > 126) {
            print_no_printable(str[i]);
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
    return 0;
}
