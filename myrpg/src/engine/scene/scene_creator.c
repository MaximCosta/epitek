/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"

static void scene_create_handlers(void (*on_render)(void *),
    void (*handle_event)(void *, sfEvent *event))
{
    scene_manager_t *scene_manager = ENGINE->scene_manager;
    size_t old_size = 0;

    if (!scene_manager->on_render) {
        scene_manager->on_render = malloc(sizeof(void *));
    } else {
        old_size = sizeof(void *) * scene_manager->scene_count;
        scene_manager->on_render = my_realloc(scene_manager->on_render,
            old_size, old_size + sizeof(void *));
    }
    if (!scene_manager->handle_event) {
        scene_manager->handle_event = malloc(sizeof(void *));
    } else {
        old_size = sizeof(void *) * scene_manager->scene_count;
        scene_manager->handle_event = my_realloc(scene_manager->handle_event,
            old_size, old_size + sizeof(void *));
    }
    scene_manager->on_render[scene_manager->scene_count] = on_render;
    scene_manager->handle_event[scene_manager->scene_count] = handle_event;
}

void scene_create(void (*on_render)(),
    void (*handle_event)(void *, sfEvent *event), void *(*on_create)(void))
{
    scene_manager_t *scene_manager = ENGINE->scene_manager;
    size_t old_size = 0;

    if (!scene_manager->scenes) {
        scene_manager->scenes = malloc(sizeof(void *));
    } else {
        old_size = sizeof(void *) * scene_manager->scene_count;
        scene_manager->scenes = my_realloc(scene_manager->scenes,
                old_size, old_size + sizeof(void *));
    }
    scene_create_handlers(on_render, handle_event);
    scene_manager->scenes[scene_manager->scene_count] = on_create();
    scene_manager->scene_count++;
}
