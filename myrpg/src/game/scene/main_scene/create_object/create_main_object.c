/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** create_main_object.c
*/

#include "../../../../../include/game/rpg.h"

static const char *BACKGROUND_S = "./assets/main/FirstGui.png";
static const char *GAME_LOGO_S = "./assets/main/GameLogo.png";
static const char *PARTICLES_S = "./assets/main/Particles.png";
static const char *BLACKSCREEN_S = "./assets/main/BlackTransition.png";

void create_main_object(main_scene_t *main_scene)
{
    object_t *particles = NULL;

    scene_add_object(&main_scene->objects,
        object_create_from_image(BACKGROUND, (loc_t){0, 0}, BACKGROUND_S));
    scene_add_object(&main_scene->objects,
        object_create_from_image(GAME_LOGO,
            (loc_t){(WIDTH / 2)
                    - object_get_size(
                        object_get_from_uuid(&main_scene->objects, GAME_LOGO))
                          .x
                    - 10,
                940},
            GAME_LOGO_S));
    scene_add_object(&main_scene->objects,
        object_create_from_image(PARTICLES, (loc_t){0, 0}, PARTICLES_S));
    particles = object_get_from_uuid(&main_scene->objects, PARTICLES);
    object_set_position(particles,
        (sfVector2f){0 - (object_get_origin_size(particles).x / 2), 0});
}
