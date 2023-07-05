/*
** EPITECH PROJECT, 2021
** my_params_to_array
** File description:
** store program's 
*/

#include "./include/my.h"
#include <stdlib.h>

struct info_param *my_params_to_array(int ac, char **av)
{
    struct info_param *p;
    char *dest = "";

    p = malloc(sizeof(struct info_param) * (ac + 1));
    for (int i = 0; i < ac; i++) {
        my_strcpy(dest,av[i]);
        p[i].length = my_strlen(av[i]); 
        p[i].str = av[i];
        p[i].copy = dest;
        p[i].word_array = my_str_to_word_array(av[i]);
    }
    p[++ac].str = 0;
    return p;
}
