/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** add_menu_sliders.c
*/

#include "../../../../../include/game/rpg.h"

static const char *SILDER_S = "./assets/GameScene/GUI/menu/slider.png";

void add_sliders(game *scene)
{
    SAO(&scene->objects, OCFI(FPS_SLIDER, (loc_t){660, 456}, SILDER_S));
    object_set_centered_origin(OGFuuid_t(&scene->objects, FPS_SLIDER));
    object_set_render_priority(OGFuuid_t(&scene->objects, FPS_SLIDER), 316);
    SAT(&scene->objects, TOC(TEXT_FPS, (loc_t){1000, 456}, "60"));
    sfText_setColor(TOGFUUID(&scene->objects, TEXT_FPS)->text, sfBlack);
    object_set_render_priority(
        TOGFUUID(&scene->objects, TEXT_FPS)->object, 317);

    SAO(&scene->objects, OCFI(VOLUME_SLIDER, (loc_t){1000, 379}, SILDER_S));
    object_set_centered_origin(OGFuuid_t(&scene->objects, VOLUME_SLIDER));
    object_set_render_priority(OGFuuid_t(&scene->objects, VOLUME_SLIDER), 318);
    SAT(&scene->objects, TOC(TEXT_VOLUME, (loc_t){1000, 379}, "60"));
    sfText_setColor(TOGFUUID(&scene->objects, TEXT_VOLUME)->text, sfBlack);
    object_set_render_priority(
        TOGFUUID(&scene->objects, TEXT_VOLUME)->object, 319);
}