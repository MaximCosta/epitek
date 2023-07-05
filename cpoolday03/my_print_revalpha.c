/*
** EPITECH PROJECT, 2021
** my_print_revalpha
** File description:
** print alpha one line
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
    for (char c = 'z'; c >= 'a'; c--) {
        my_putchar(c);
    }
    return 0;
}
