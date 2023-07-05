/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"

void scene_change(int scene)
{
    gui_close();
    ENGINE->scene_manager->current_scene = scene;
}
