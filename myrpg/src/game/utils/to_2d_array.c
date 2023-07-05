/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** to_2d_array.c
*/

#include "../../../include/game/rpg.h"

char **class_to_array(char **array, char *str, int height)
{
    char *this_str = my_strdup("");
    int i = 0;

    for (int e = 0; e != height; e++) {
        for (; str[i] != '\n'; i++)
            this_str = my_strcat_char(this_str, str[i]);
        array[e] = my_strdup(this_str);
        this_str = my_strdup("");
        i++;
    }
    return array;
}

char **to_2d_array(char *str)
{
    char **array = NULL;
    int i = 0;
    int height = 0;

    for (;str[i] != '\n'; i++);
    array = malloc(sizeof(char *) * (i + 1));
    array[i] = NULL;
    for (i = 0; str[i]; i++)
        if (str[i] == '\n')
            height++;
    return class_to_array(array, str, height);
}
