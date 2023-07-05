/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** task02
*/
#include<unistd.h>

void my_putchar(char c);

void my_putstr(char const *str)
{
    int	a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
}
