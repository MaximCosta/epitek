/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../../include/engine/engine.h"

textobject_t *textobject_create(uuid_t uuid,loc_t location, const char *text)
{
    textobject_t *textobj = malloc(sizeof(textobject_t));
    object_t *text_obj = object_create(uuid, location);
    sfText *sf_text = sfText_create();

    sfText_setString(sf_text, text);
    sfText_setPosition(sf_text, (sfVector2f){location.x, location.y});
    sfText_setFont(sf_text, ENGINE->default_font);
    textobj->object = text_obj;
    textobj->text = sf_text;
    return textobj;
}

textobject_t *textobject_get_from_uuid(list_t **objects, uuid_t uuid)
{
    list_t *object = *objects;

    while (object) {
        if (CAST(objectany_t *, object->value)->type == TEXT
            && object_get_from_any(object->value)->uuid == uuid)
            return CAST(
                textobject_t *, CAST(objectany_t *, object->value)->object);
        object = object->next;
    }
    return 0;
}

void textobject_set_string(textobject_t *object, const char *text)
{
    sfText_setString(object->text, text);
}

void textobject_set_font(textobject_t *object, sfFont *font)
{
    sfText_setFont(object->text, font);
}

void textobject_set_size(textobject_t *object, unsigned int size)
{
    sfText_setCharacterSize(object->text, size);
}
