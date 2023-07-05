/*
** EPITECH PROJECT, 2021
** star
** File description:
** write star on terminal
*/

void my_putchar(char c);
void center_part_2(unsigned int i);
void bottom(unsigned int i);

void print_loop(int val, char c)
{
    for (int x = 0; x < val; x++) {
        my_putchar(c);
    }
}

void top(unsigned int i)
{
    if (i == 1) {
        print_loop(3, ' ');
        my_putchar('*');
        my_putchar('\n');
        return;
    }
    for (int x = 0; x < i; x++) {
        print_loop(i * 3 - 1 - x, ' ');
        my_putchar('*');
        if (x > 0) {
            print_loop(x * 2 - 1, ' ');
            my_putchar('*');
        }
        my_putchar('\n');
    }
}

void center_part_1(unsigned int i)
{

    print_loop(i * 2 + 1, '*');
    if (i > 1)
        print_loop((i - 1) * 2 - 1, ' ');
    else
        my_putchar(' ');
    print_loop(i * 2 + 1, '*');
    my_putchar('\n');
    for (int x = 0; x < i; x++) {
        print_loop(x + 1, ' ');
        my_putchar('*');
        if (i > 1)
            print_loop((6 * i - 5) - (2 * x), ' ');
        else
            print_loop(3, ' ');
        my_putchar('*');
        my_putchar('\n');
    }
}

void star(unsigned int size)
{
    if (size <= 0)
        return;
    top(size);
    center_part_1(size);
    center_part_2(size);
    bottom(size);
}
