/*
** EPITECH PROJECT, 2021
** my_print_digits
** File description:
** return all digits
*/

void my_putchar(char c);

int my_print_digits(void)
{
    for (char i = '0'; i <= '9'; i++) {
        my_putchar(i);
    }
    return 0;
}
