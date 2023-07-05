/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** get_all_selected.c
*/

#include "../../../../../include/game/rpg.h"

bool get_all_selected(game *scene, inventory_t *invent)
{
    int i = 0;

    for (; i != 32; i++) {
        if (&scene->cases[i] == invent)
            continue;
        if (scene->cases[i].selected == true)
            return false;
    }
    for (i = 0; i != 4; i++) {
        if (&scene->equiped[i] == invent)
            continue;
        if (scene->equiped[i].selected == true)
            return false;
    }
    return true;
}
