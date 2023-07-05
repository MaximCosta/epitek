/*
** EPITECH PROJECT, 2021
** B-BOO-101-MPL-1-1-phoenixd01-maxim.costa [WSL: Ubuntu]
** File description:
** show_combinations
*/

void my_putchar(char c);

int next(char i, char j)
{
    for (int k = j+1; k <= '9'; k++) {
        my_putchar(i);
        my_putchar(j);
        my_putchar(k);
        if (k != '9' || j != '8' || i != '7') {
            my_putchar(',');
            my_putchar(' ');
        }
    }
}

int show_combinations(void)
{
    for (char i = '0'; i < '9'; i++)
        for (char j = i+1; j < '9'; j++)
            next(i, j);
}
