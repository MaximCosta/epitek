/*
** EPITECH PROJECT, 2022
** mydefender [WSL: Ubuntu]
** File description:
** csfml_func
*/

#include "defender.h"

sfRenderWindow *gw(sfVideoMode m, char *str)
{
    return sfRenderWindow_create(m, str, sfResize | sfClose, NULL);
}
