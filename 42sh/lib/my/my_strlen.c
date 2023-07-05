/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int n = 0;

    while (str[n])
        n++;
    return n;
}
