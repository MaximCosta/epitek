/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"

object_t *object_get_from_any(void *object_any)
{
    object_t *obj = 0;

    if (CAST(objectany_t *, object_any)->type == OBJECT)
        obj = CAST(objectany_t *, object_any)->object;
    if (CAST(objectany_t *, object_any)->type == ENTITY)
        obj = CAST(entity_t *, CAST(objectany_t *, object_any)->object)->object;
    if (CAST(objectany_t *, object_any)->type == TEXT)
        obj = CAST(textobject_t *, CAST(
            objectany_t * , object_any)->object)->object;
    return obj;
}
