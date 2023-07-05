/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** scene_settings.c
*/
#include "../../../../../include/game/rpg.h"

void create_object_load(LoadScene *load_scene);

char **get_subtitle(char **subtitle);

void initiate_scene(LoadScene *scene)
{
    scene->index_subtitle = 0;
    scene->text = "";
    scene->sub = 0;
    scene->mouse_press = false;
    scene->subtitle = get_subtitle(scene->subtitle);
    create_object_load(scene);
}
