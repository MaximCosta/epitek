/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** info_rect_plus.c
*/

#include "../../../../../include/game/rpg.h"

bool mouse_inside(object_t *object);

void rect_load_skills(game *scene)
{
    object_t *l_shield = object_get_from_uuid(&scene->objects, LOAD_SHIELD);
    object_t *l_damage = object_get_from_uuid(&scene->objects, LOAD_DAMAGE);
    object_t *l_speed = object_get_from_uuid(&scene->objects, LOAD_SPEED);
    object_t *shield = object_get_from_uuid(&scene->objects, INFO_SHIELD);
    object_t *damage = object_get_from_uuid(&scene->objects, INFO_DAMAGE);
    object_t *speed = object_get_from_uuid(&scene->objects, INFO_SPEED);

    if (!mouse_inside(shield) || !scene->stats->active)
        object_set_rect(l_shield, (sfIntRect){0, 0, 0, 80});
    if (!mouse_inside(damage) || !scene->stats->active)
        object_set_rect(l_damage, (sfIntRect){0, 0, 0, 80});
    if (!mouse_inside(speed) || !scene->stats->active)
        object_set_rect(l_speed, (sfIntRect){0, 0, 0, 80});
}

void info_rect_speed(game *scene, object_t *stats, object_t *speed)
{
    if (mouse_inside(speed) &&
    object_get_rect(stats).height >= 300 &&
    scene->player->PAUSE) {
        object_set_rect(speed, (sfIntRect){224, 0, 224, 165});
        if (scene->mouse_press)
            scene->stats->LOAD_SPEED = true;
        else
            scene->stats->LOAD_SPEED = false;
    } else {
        object_set_rect(speed, (sfIntRect){0, 82.5, 224, 82.5});
        scene->stats->LOAD_SPEED = false;
    }
}

void info_rect_damage(game *scene, object_t *stats, object_t *damage)
{
    if (mouse_inside(damage) &&
    object_get_rect(stats).height >= 300 &&
    scene->player->PAUSE) {
        object_set_rect(damage, (sfIntRect){224, 0, 224, 165});
        if (scene->mouse_press)
            scene->stats->LOAD_DAMAGE = true;
        else
            scene->stats->LOAD_DAMAGE = false;
    } else {
        object_set_rect(damage, (sfIntRect){0, 82.5, 224, 82.5});
        scene->stats->LOAD_DAMAGE = false;
    }

}

void update_dolex_text(game *scene)
{
    object_t *stats = object_get_from_uuid(&scene->objects, PLAYER_STATS);
    textobject_t *dolex = textobject_get_from_uuid(&scene->objects, DOLEX_TXT);

    if (scene->stats->dolex != 0)
        textobject_set_string(dolex, my_itoa(scene->stats->dolex, 0));
    else
        textobject_set_string(dolex, "0");
    if (object_get_rect(stats).height >= 50)
        object_set_visible(dolex->object, true);
    else
        object_set_visible(dolex->object, false);
}
