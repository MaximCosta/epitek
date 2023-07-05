/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"

void scene_manager_init(void)
{
    ENGINE->scene_manager = malloc(sizeof(scene_manager_t));
    ENGINE->scene_manager->handle_event = 0;
    ENGINE->scene_manager->scene_count = 0;
    ENGINE->scene_manager->on_render = 0;
    ENGINE->scene_manager->current_scene = 0;
    ENGINE->scene_manager->scenes = 0;
}

void scene_add_entity(list_t **object_list, void *entity)
{
    objectany_t *object_any = malloc(sizeof(objectany_t));

    object_any->type = ENTITY;
    object_any->object = entity;
    list_insert_end(object_list, object_any);
    object_sort(object_list);
}

void scene_add_object(list_t **object_list, void *object)
{
    objectany_t *object_any = malloc(sizeof(objectany_t));

    object_any->type = OBJECT;
    object_any->object = object;
    list_insert_end(object_list, object_any);
    object_sort(object_list);
}

void scene_add_text(list_t **object_list, void *text)
{
    objectany_t *object_any = malloc(sizeof(objectany_t));

    object_any->type = TEXT;
    object_any->object = text;
    list_insert_end(object_list, object_any);
    object_sort(object_list);
}

bool scene_is_current(int scene)
{
    return scene_get(scene) == scene_get_current();
}
