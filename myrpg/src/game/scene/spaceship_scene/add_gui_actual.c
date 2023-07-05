/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** add_gui_actual.c
*/

#include "../../../../include/game/rpg.h"

static const char *CURRENT_S = "./assets/SpaceShip/current.png";
static const char *TO_lAND_S = "./assets/SpaceShip/to_land.png";

void just_check(object_t *object);

void to_land_click(SpaceShip *scene)
{
    if (scene->lock)
        return;
    scene->current_planet = my_strdup(scene->new_current);
    scene->press = false;
    scene->lock = true;
    scene_change(LOAD_SCENE);
}

void update_current(SpaceShip *scene)
{
    space_planete_t *pl = scene->planete;
    object_t *current = OGFuuid_t(&scene->objects, CURRENT);
    object_t *object = OGFuuid_t(&scene->objects, 600);

    for (; pl != NULL; pl = pl->next) {
        if (equal(scene->current_planet,
        (char *)sfText_getString(pl->title->text)))
            OSP(current, (V2F){OGP(pl->object).x - 52,
            OGP(pl->object).y - 80});
    }
    if (object_on_hover(OGFuuid_t(&scene->objects, 600), &just_check)) {
        if (!scene->lock)
            object_set_rect(object, (sfIntRect){195, 0, 190, 68});
        if (scene->press) {
            scene->press = false;
            to_land_click(scene);
        }
    } else {
        if (!scene->lock)
            object_set_rect(object, (sfIntRect){0, 0, 198, 68});
        else
            object_set_rect(object, (sfIntRect){390, 0, 190, 68});
    }
}

void add_gui_current(SpaceShip *scene)
{
    object_t *current = OCFI(CURRENT, (loc_t){1540, 500}, CURRENT_S);
    object_t *to_land = OCFI(600, (loc_t){960 - 99, 950}, TO_lAND_S);

    scene->lock = false;
    SAO(&scene->objects, current);
    SAO(&scene->objects, to_land);
    object_set_render_priority(current, 1);
    object_set_render_priority(to_land, 201);
    object_set_rect(to_land, (sfIntRect){0, 0, 198, 68});
    scene->current_planet = my_strdup("BAREN");
}
