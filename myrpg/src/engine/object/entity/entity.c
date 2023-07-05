/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../../include/engine/engine.h"

entity_t *entity_create(list_t *objects, list_t *entities, path_t texture_path)
{
    entity_t *entity = malloc(sizeof(entity_t));
    object_t *entity_obj = object_create_from_image(-1,
        (loc_t) {.y = 100, .x = 100}, texture_path);

    entity->state = IDLE;
    entity->object = entity_obj;
    entity->health = 20.0;
    entity->speed = 1.0;
    scene_add_entity(&entities, entity);
    return entity;
}
