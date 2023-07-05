/*
** EPITECH PROJECT, 2021
** B-BOO-101-MPL-1-1-phoenixd01-maxim.costa [WSL: Ubuntu]
** File description:
** show_alphabet
*/

void my_putchar(char c);

int show_alphabet(void)
{
    for (int i = 'a'; i <= 'z'; i++)
        my_putchar(i);
}
