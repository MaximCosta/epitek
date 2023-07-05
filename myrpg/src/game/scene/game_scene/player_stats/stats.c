/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** stats.c
*/

#include "../../../../../include/game/rpg.h"

static const char *LOAD_SHIELD_S = "./assets/GameScene/GUI/load_shield.png";
static const char *LOAD_DAMAGE_S = "./assets/GameScene/GUI/load_damage.png";
static const char *LOAD_SPEED_S = "./assets/GameScene/GUI/load_speed.png";

void create_load_skills(game *scene)
{
    scene_add_object(&scene->objects, object_create_from_image(
        LOAD_SHIELD, (loc_t){44, 123}, LOAD_SHIELD_S));
    scene_add_object(&scene->objects, object_create_from_image(
        LOAD_DAMAGE, (loc_t){44, 223}, LOAD_DAMAGE_S));
    scene_add_object(&scene->objects, object_create_from_image(
        LOAD_SPEED, (loc_t){44, 323}, LOAD_SPEED_S));
    object_set_render_priority(object_get_from_uuid(&scene->objects,
        LOAD_SHIELD), 114);
    object_set_render_priority(object_get_from_uuid(&scene->objects,
        LOAD_DAMAGE), 115);
    object_set_render_priority(object_get_from_uuid(&scene->objects,
        LOAD_SPEED), 116);
}

void stats(game *scene)
{
    create_load_skills(scene);
    object_set_render_priority(object_get_from_uuid(&scene->objects,
        PLAYER_STATS), 105);
    object_set_render_priority(textobject_get_from_uuid(&scene->objects,
        STATS_MAXPV_TXT)->object, 107);
    object_set_render_priority(textobject_get_from_uuid(&scene->objects,
        STATS_DAMAGE_TXT)->object, 108);
    object_set_render_priority(textobject_get_from_uuid(&scene->objects,
        STATS_SPEED_TXT)->object, 109);
    object_set_render_priority(object_get_from_uuid(&scene->objects,
        INFO_SHIELD), 110);
    object_set_render_priority(object_get_from_uuid(&scene->objects,
        INFO_DAMAGE), 111);
    object_set_render_priority(object_get_from_uuid(&scene->objects,
        INFO_SPEED), 112);
    object_set_render_priority(object_get_from_uuid(&scene->objects,
        INFO_DOLEX), 113);
}
