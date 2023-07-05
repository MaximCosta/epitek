/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** object_position.c
*/

#include "../../../include/engine/engine.h"

void object_set_position(object_t *object, sfVector2f location)
{
    if (!object)
        return;
    sfSprite_setPosition(object->sprite, location);
}

sfVector2f object_get_position(object_t *object)
{
    if (!object)
        return (sfVector2f){0, 0};
    return sfSprite_getPosition(object->sprite);
}

sfVector2f textobject_get_position(textobject_t *textobject)
{
    if (!textobject)
        return (sfVector2f){0, 0};
    return sfText_getPosition(textobject->text);
}
