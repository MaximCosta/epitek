/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** auto_inventory.c
*/

#include "../../../../../include/game/rpg.h"

void class_invent(game *scene)
{
    int i = 0;
    inventory_t tmp;

    for (; i != 32; i++) {
        if (i + 1 < 32 && scene->cases[i].item == NULL &&
        scene->cases[i + 1].item != NULL) {
            tmp = scene->cases[i];
            scene->cases[i] = scene->cases[i + 1];
            scene->cases[i + 1] = tmp;
        }
    }
}

void class_equiped(game *scene)
{
    int i = 0;
    inventory_t tmp;

    for (; i != 5; i++) {
        if (i + 1 < 5 && scene->equiped[i].item == NULL &&
        scene->equiped[i + 1].item != NULL) {
            tmp = scene->equiped[i];
            scene->equiped[i] = scene->equiped[i + 1];
            scene->equiped[i + 1] = tmp;
        }
    }
}

void auto_inventory_class(game *scene)
{
    class_invent(scene);
    class_equiped(scene);
}
