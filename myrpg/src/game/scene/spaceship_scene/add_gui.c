/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** add_gui.c
*/

#include "../../../../include/game/rpg.h"

static const char *SPACE_CURSOR_S = "./assets/main/cursor.png";
static const char *LESS_SPEED_S = "./assets/SpaceShip/less_speed.png";
static const char *MORE_SPEED_S = "./assets/SpaceShip/more_speed.png";

void add_stats_panel(SpaceShip *scene);
void add_gui_current(SpaceShip *scene);

void hover(object_t *object)
{
    object_set_rect(object, (sfIntRect){82, 0, 82, 50});
}

void unhover(object_t *object)
{
    object_set_rect(object, (sfIntRect){0, 0, 82, 50});
}

void less_planets(object_t *object)
{

    SpaceShip *scene = (SpaceShip *) scene_get_current();

    if (scene->ratio - 0.1 > 0)
        scene->ratio -= 0.1;
}

void more_planets(object_t *object)
{

    SpaceShip *scene = (SpaceShip *) scene_get_current();

    scene->ratio += 0.1;
}

void add_gui_space(SpaceShip *scene)
{
    object_t *less_speed = OCFI(LESS_SPEED, (loc_t){60, 131}, LESS_SPEED_S);
    object_t *more_speed = OCFI(MORE_SPEED, (loc_t){300, 131}, MORE_SPEED_S);

    scene->mouse = object_create_from_image(
        SPACE_CURSOR, (loc_t){0, 0}, SPACE_CURSOR_S);
    scene_add_object(&scene->objects, scene->mouse);
    object_set_render_priority(scene->mouse, 1000);
    object_set_rect(scene->mouse, (sfIntRect){0, 0, 32, 32});
    object_set_centered_origin(scene->mouse);
    scene_add_object(&scene->objects, less_speed);
    scene_add_object(&scene->objects, more_speed);
    object_set_rect(less_speed, (sfIntRect){0, 0, 82, 50});
    object_set_rect(more_speed, (sfIntRect){0, 0, 82, 50});
    object_on_hover(less_speed, &hover);
    object_on_unhover(less_speed, &unhover);
    object_on_hover(more_speed, &hover);
    object_on_unhover(more_speed, &unhover);
    object_on_click(less_speed, &less_planets);
    object_on_click(more_speed, &more_planets);
    add_stats_panel(scene);
    add_gui_current(scene);
}
