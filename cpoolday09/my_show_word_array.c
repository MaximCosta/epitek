/*
** EPITECH PROJECT, 2021
** my_show_param_array
** File description:
** show parameter
*/


#include "./include/my.h"
#include <stdlib.h>

int my_show_word_array(struct info_param const *par)
{

    for (int i = 0; par[i].str != 0; i++) {
        my_put_nbr(par[i].length);
        my_putchar('\n');
        my_putstr(par[i].str);
        my_putchar('\n');
        for (int j = 0; par[i].word_array; j++) {
            my_putstr(par[i].word_array[j]);
            my_putchar('\n');
        }
    }
    return 0;
}
