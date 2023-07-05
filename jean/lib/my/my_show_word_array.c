/*
** EPITECH PROJECT, 2021
** Pool Day08
** File description:
** my_show_word_array
*/

#include "my.h"

int my_show_word_array(char * const *tab)
{
    while (*tab) {
        my_putstr(*tab++);
        my_putchar('\n');
    }
    return (0);
}
