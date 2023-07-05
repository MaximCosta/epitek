/*
** EPITECH PROJECT, 2021
** my_print_comb
** File description:
** return all number without double
*/

void my_putchar(char c);

int print_result(char i1, char i2, char i3)
{
    my_putchar(i1);
    my_putchar(i2);
    my_putchar(i3);
    if (i1 != '7' || i2 != '8' || i3 != '9') {
        my_putchar(',');
        my_putchar(' ');
    }
    return 0;
}

int print_loop(char i1, char i2)
{
    for (char i3 = i2 + 1; i3 <= '9'; i3++) {
        if (i1 != i2 && i2 != i3 && i1 != i3) {
            print_result(i1, i2, i3);
        }
    }
    return 0;
}

int my_print_comb(void)
{
    for (char i1 = '0'; i1 <= '9'; i1++) {
        for (char i2 = i1 + 1; i2 <= '9'; i2++) {
            print_loop(i1, i2);
        }
    }
    return 0;
}
