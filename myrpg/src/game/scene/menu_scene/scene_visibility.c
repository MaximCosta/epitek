/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** scene_visibility.c
*/

#include "../../../../include/game/rpg.h"

static const char *PEACEFUL_S = "./assets/menu/PeacefulD.png";
static const char *NORMAL_S = "./assets/menu/NormalD.png";
static const char *HARD_S = "./assets/menu/HardD.png";
static const char *PERMANENT_S = "./assets/menu/PermanentD.png";

void initiate_then(MenuScene *scene)
{
    object_t *peaceful;
    object_t *normal;
    object_t *hard;
    object_t *permanent;
    object_t *back;

    peaceful = object_get_from_uuid(&scene->objects, PEACEFUL);
    normal = object_get_from_uuid(&scene->objects, NORMAL);
    hard = object_get_from_uuid(&scene->objects, HARD);
    permanent = object_get_from_uuid(&scene->objects, PERMANENT);
    back = object_get_from_uuid(&scene->objects, BACK_TO_MENU);
    object_set_visible(back, true);
    object_set_visible(peaceful, true);
    object_set_visible(normal, true);
    object_set_visible(hard, true);
    object_set_visible(permanent, true);
    object_set_position(back, (sfVector2f){350, 940});
    object_set_rectlist((object_t *[4]){peaceful, normal, hard,
    permanent}, (sfIntRect){0, 0, 400, 820}, 4);
    scene->selected = 1;
}

void add_new_objects(MenuScene *scene)
{
    static int i = 0;

    if (i == 0) {
    scene_add_object(&scene->objects, object_create_from_image(
        PEACEFUL, (loc_t){90, 70}, PEACEFUL_S));
    scene_add_object(&scene->objects, object_create_from_image(
        NORMAL, (loc_t){540, 70}, NORMAL_S));
    scene_add_object(&scene->objects, object_create_from_image(
        HARD, (loc_t){990, 70}, HARD_S));
    scene_add_object(&scene->objects, object_create_from_image(
        PERMANENT, (loc_t){1440, 70}, PERMANENT_S));
        i++;
    }
    initiate_then(scene);
}

void scene_visibility(MenuScene *scene, bool fade_out)
{
    object_t *play_button = object_get_from_uuid(&scene->objects, PLAY_BUTTON);
    object_t *multi_button = object_get_from_uuid(&scene->objects,
    MULTIPLAYER_BUTTON);
    object_t *title = object_get_from_uuid(&scene->objects, TITLE);
    object_t *back = object_get_from_uuid(&scene->objects, BACK_TO_MENU);

    if (scene->slected_difficulty && fade_out) {
            object_set_visible(play_button, false);
            object_set_visible(multi_button, false);
            object_set_visible(title, false);
            if (scene->selected == 0)
                add_new_objects(scene);
    }
}
