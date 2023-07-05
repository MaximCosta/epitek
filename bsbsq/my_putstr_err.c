/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-maxim.costa
** File description:
** my_putstr_err
*/

void my_putchar_err(char c);

int my_putstr_err(char const *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar_err(str[i]);
        i++;
    }
    return 0;
}
