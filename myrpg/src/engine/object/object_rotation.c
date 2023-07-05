/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** object_rotation.c
*/

#include "../../../include/engine/engine.h"

void object_set_rotation(object_t *object, float angle)
{
    if (!object)
        return;
    sfSprite_setRotation(object->sprite, angle);
}

float object_get_rotation(object_t *object)
{
    if (!object)
        return 0.00;
    return sfSprite_getRotation(object->sprite);
}
