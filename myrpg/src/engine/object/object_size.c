/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** object_size.c
*/

#include "../../../include/engine/engine.h"

sfVector2f object_get_size(object_t *object)
{
    sfFloatRect local;

    if (!object)
        return (sfVector2f){0, 0};
    local = sfSprite_getLocalBounds(object->sprite);
    return (sfVector2f){local.width, local.height};
}

sfVector2f object_get_origin_size(object_t *object)
{
    sfVector2u local;

    if (!object)
        return (sfVector2f){0, 0};
    local = sfTexture_getSize(sfSprite_getTexture(object->sprite));
    return (sfVector2f){local.x, local.y};
}
