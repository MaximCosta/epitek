/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"

void *scene_get(int scene)
{
    return ENGINE->scene_manager->scenes[scene];
}

void *scene_get_current()
{
    if (!ENGINE->scene_manager->scenes)
        return 0;
    return ENGINE->
        scene_manager->scenes[ENGINE->scene_manager->current_scene];
}

int scene_get_current_index(void)
{
    return ENGINE->scene_manager->current_scene;
}
