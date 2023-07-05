/*
** EPITECH PROJECT, 2021
** B-BOO-101-MPL-1-1-phoenixd01-maxim.costa [WSL: Ubuntu]
** File description:
** show_string
*/

void my_putchar(char c);

int show_string(char const *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
    return 0;
}
