/*
** EPITECH PROJECT, 2021
** my_print_combn
** File description:
** comb with n lengths
*/

int check_raw(int n);
void my_putchar(char c);
int my_put_nbr(int val);

int checkmin(int val, int size)
{
    int f;
    int locmin = 10;

    while (size > 0) {
        f = val % 10;
        val /= 10;
        size /= 10;
        if (locmin > f) {
            locmin = f;
        } else {
            return 0;
        }
    }
    return 1;
}

int nb_len(int val)
{
    int i = 0;

    while (val > 0) {
        i++;
        val /= 10;
    }
    return i;
}

int power(int x, int d)
{
    for (int i = 1; i <= d; i++) {
        x *= 10;
    }
    return x;
}

int combn_print(int val, int max, int first)
{
    if (first != 1) {
        my_putchar(',');
        my_putchar(' ');
    }
    if (nb_len(val) < nb_len(max)) {
        my_putchar('0');
    }
    my_put_nbr(val);
    return 0;
}

int my_print_combn(int n)
{
    int use = 0;
    int max = power(10, n - 1) - 1;
    int size = power(1, nb_len(use) - 1);
    int first = 1;

    if (check_raw(n))
        return 0;

    for (int i = 1; i < n; i++) {
        use = use * 10 + i;
    }
    while (use <= max) {
        if (nb_len(use) >= nb_len(size) + 1) {
            size *= 10;
        }
        if (checkmin(use, size)) {
            combn_print(use, max, first);
            first = 0;
        }
        use++;
    }
    return 0;
}