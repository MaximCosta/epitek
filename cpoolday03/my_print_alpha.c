/*
** EPITECH PROJECT, 2021
** my_print_alpha
** File description:
** print alpha one line
*/

void my_putchar(char c);

int my_print_alpha(void)
{
    for (char c = 'a'; c <= 'z'; c++) {
        my_putchar(c);
    }
    return 0;
}
