/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"

object_t *object_create(uuid_t uuid, loc_t location)
{
    object_t *object = malloc(sizeof(object_t));

    object->render_priority = 0;
    object->uuid = uuid;
    object->location = location;
    object->sprite = sfSprite_create();
    object->visible = true;
    object->hovered = false;
    object->on_click = 0;
    object->on_hover = 0;
    object->on_unhover = 0;
    object->animations = 0;
    return object;
}

object_t *object_create_sprite(uuid_t uuid,loc_t location, sfSprite *sprite)
{
    object_t *object = object_create(uuid, location);

    object->sprite = sprite;
    return object;
}

object_t *object_create_from_image(uuid_t uuid,
       loc_t location, path_t path)
{
    object_t *object = object_create(uuid, location);

    sfSprite_setPosition(object->sprite,
        (sfVector2f) {location.x, location.y});
    sfSprite_setTexture(object->sprite,
            sfTexture_createFromFile(path, NULL), sfFalse);
    return object;
}

object_t *object_get_from_uuid(list_t **objects, uuid_t uuid)
{
    list_t *object = *objects;

    while (object) {
        if (CAST(objectany_t *, object->value)->type == OBJECT &&
            object_get_from_any(object->value)->uuid == uuid)
            return object_get_from_any(object->value);
        object = object->next;
    }
    return 0;
}
