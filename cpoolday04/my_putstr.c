/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** write one by one char of string
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;
    char val = *(str + i);

    while (val) {
        my_putchar(val);
        val = *(str + ++i);
    }
    return 0;
}
