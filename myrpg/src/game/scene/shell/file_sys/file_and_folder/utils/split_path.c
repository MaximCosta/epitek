/*
** EPITECH PROJECT, 2021
** FILE
** File description:
** split_path.c
*/

#include "../../../../../../../include/game/rpg.h"
#include <stdlib.h>

static int get_nbr_of_char(char *s, char c)
{
    int nbr = 0;

    for (int i = 0; s[i]; i++)
        if (s[i] == c)
            nbr++;
    return nbr;
}

static int my_get_index(char *s, char c)
{
    for (int i = 0; s[i]; i++)
        if (s[i] == c)
            return i;
    return -1;
}

char **split_path(char *path)
{
    int nb = get_nbr_of_char(path, '/');
    char **tab = my_calloc(sizeof(char *) * (nb + 2));
    char *tmp = my_strdup(path);

    path = tmp;
    for (int i = 0;; i += nb != 0) {
        nb = my_get_index(path, '/');
        if (nb == -1) {
            tab[i] = *path ? my_strdup(path) : 0;
            free(tmp);
            return tab;
        } else if (nb == 0) {
            path++;
            continue;
        } else {
            path[nb] = '\0';
            tab[i] = my_strdup(path);
            path = path + nb + 1;
        }
    }
}