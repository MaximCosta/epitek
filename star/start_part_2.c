/*
** EPITECH PROJECT, 2021
** start_part_2
** File description:
** star print part 2
*/

void print_loop(int i, char c);

void my_putchar(char c);

void center_part_2(unsigned int i)
{
    for (int x = i; x > 1; x--) {
        print_loop(x - 1, ' ');
        my_putchar('*');
        print_loop((6 * i - 2) - (2 * x - 1), ' ');
        my_putchar('*');
        my_putchar('\n');
    }
    print_loop(i * 2 + 1, '*');
    if (i > 1)
        print_loop((i - 1) * 2 - 1, ' ');
    else
        my_putchar(' ');
    print_loop(i * 2 + 1, '*');
    my_putchar('\n');
}

void bottom(unsigned int i)
{
    if (i == 1) {
        print_loop(3, ' ');
        my_putchar('*');
        my_putchar('\n');
        return;
    }
    for (int x = i - 1; x >= 0; x--) {
        print_loop(i * 3 - 1 - x, ' ');
        my_putchar('*');
        if (x > 0) {
            print_loop(x * 2 - 1, ' ');
            my_putchar('*');
        }
        my_putchar('\n');
    }
}
