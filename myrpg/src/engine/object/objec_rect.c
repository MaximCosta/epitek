/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** objec_rect.c
*/

#include "../../../include/engine/engine.h"

void object_set_rect(object_t *object, sfIntRect rect)
{
    if (!object)
        return;
    sfSprite_setTextureRect(object->sprite, rect);
}

void object_set_rectlist(object_t **object, sfIntRect rect, int size)
{
    if (!object)
        return;
    for (int i = 0; i != size; i++)
        sfSprite_setTextureRect(object[i]->sprite, rect);
}

sfIntRect object_get_rect(object_t *object)
{
    if (!object)
        return (sfIntRect){0, 0, 0, 0};
    return sfSprite_getTextureRect(object->sprite);
}
