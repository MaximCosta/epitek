/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** create_object.c
*/

#include "../../../../../include/game/rpg.h"

static const char *LOAD_BACKGROUND_S = "./assets/Load/Animation.png";
static const char *LOAD_BLACKSCREEN_S = "./assets/main/BlackTransition.png";
static const char *SKIP_S = "./assets/Load/Skip.png";

void create_object_load(LoadScene *load_scene)
{
    scene_add_object(&load_scene->objects,
        object_create_from_image(
            LOAD_BACKGROUND, (loc_t){960, 540}, LOAD_BACKGROUND_S));
    scene_add_object(&load_scene->objects,
        object_create_from_image(SKIP, (loc_t){1450, 1000}, SKIP_S));
    scene_add_object(&load_scene->objects,
        object_create_from_image(
            LOAD_BLACKSCREEN, (loc_t){0, 0}, LOAD_BLACKSCREEN_S));
}
