/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday08-kilyan.cotten
** File description:
** my_show_word_array.c
*/

int my_putstr(char const *s);
int my_putchar(char c);
#include <stdio.h>

int my_show_word_array(char * const *tab)
{
    int i = 0;

    while (tab[i]) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}
