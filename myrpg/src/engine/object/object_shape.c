/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"

void object_set_origin(object_t *object, sfVector2f origin)
{
    if (!object)
        return;
    sfSprite_setOrigin(object->sprite, origin);
}

void object_set_scale(object_t *object, sfVector2f scale)
{
    if (!object)
        return;
    sfSprite_setScale(object->sprite, scale);
}

sfVector2f object_get_scale(object_t *object)
{
    if (!object)
        return (sfVector2f){0, 0};
    return sfSprite_getScale(object->sprite);
}

void object_set_centered_origin(object_t *object)
{
    sfFloatRect rect = sfSprite_getLocalBounds(object->sprite);

    sfSprite_setOrigin(object->sprite,
        (sfVector2f){.x = rect.width / 2, .y = rect.height / 2});
}

void object_set_texture(object_t *object, sfTexture *texture)
{
    sfTexture_destroy(
        CAST(sfTexture *, sfSprite_getTexture(object->sprite)));
    sfSprite_setTexture(object->sprite, texture, sfFalse);
}
