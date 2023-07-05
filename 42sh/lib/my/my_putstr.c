/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** my_put_str
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int n = 0;

    while (str[n]) {
        my_putchar(str[n]);
        n++;
    }
    return 0;
}
