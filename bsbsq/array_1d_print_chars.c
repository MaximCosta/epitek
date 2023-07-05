/*
** EPITECH PROJECT, 2021
** array_1d_print_chars
** File description:
** :wq
*/

void my_putchar(char c);

void array_1d_print_chars(char const* arr)
{
    for (int i = 0; arr[i]; i++) {
        my_putchar(arr[i]);
        my_putchar('\n');
    }
}
