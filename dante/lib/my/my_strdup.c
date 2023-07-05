/*
** EPITECH PROJECT, 2021
** my_strdup.c Hadès Cuisinier
** File description:
** task
*/

#include <stdlib.h>
#include <unistd.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *mot = malloc(sizeof(char) * (my_strlen(src) + 1));
    int cpt = 0;

    while (src[cpt] != '\0') {
        mot[cpt] = src[cpt];
        cpt = cpt + 1;
    }
    mot[cpt] = '\0';
    return  mot;
}
