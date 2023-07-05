/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** add_stats_panel.c
*/

#include "../../../../include/game/rpg.h"

static const char *STATS_PANEL_S = "./assets/SpaceShip/stats_panel.png";

void update_stats_panel(SpaceShip *scene)
{
    if (scene->n_stats > 0)
        object_set_visible(scene->stats_panel, true);
    else
        object_set_visible(scene->stats_panel, false);
}

void add_stats_panel(SpaceShip *scene)
{
    scene->stats_panel = OCFI(STATS_PANEL, (loc_t){1540, 500}, STATS_PANEL_S);
    SAO(&scene->objects, scene->stats_panel);
    object_set_render_priority(scene->stats_panel, 100);
}
