/*
** EPITECH PROJECT, 2021
** my_print_comb2
** File description:
** Write a function that displays, in ascending order
*/

void my_putchar(char c);

int print(int n)
{
    int a = (n / 10) + '0';
    int b = (n % 10) + '0';

    my_putchar(a);
    my_putchar(b);
    return 0;
}

int my_print_2(int a, int b)
{
    if (a != 98 || b != 99) {
        my_putchar(',');
        my_putchar(' ');
    }
    return 0;
}

int my_print_comb2(void)
{
    int a = 0;
    int b = 1;

    while (a < 99) {
        b = a + 1;
        while (b < 100) {
            print(a);
            my_putchar(' ');
            print(b);
            my_print_2(a, b);
            b = b + 1;
        }
        a = a + 1;
    }
    return 0;
}
