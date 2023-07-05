/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** player_stats.c
*/

#include "../../../../../include/game/rpg.h"

#define TGFU textobject_get_from_uuid

void just_check(object_t *object);

void update_stats(game *scene);

void btn_active(game *scene, object_t *stats_btn)
{
    if (object_on_hover(stats_btn, &just_check) && scene->player->PAUSE &&
    !object_on_hover(scene->stats->lock, &just_check)) {
        object_set_rect(stats_btn, (sfIntRect){771, 0, 257, 20});
        if (scene->mouse_press) {
            scene->mouse_press = false;
            scene->stats->active = false;
            scene->stats->is_lock = false;
        }
    } else if (scene->player->PAUSE) {
        object_set_rect(stats_btn, (sfIntRect){514, 0, 257, 20});
    }
}

void btn_deactive(game *scene, object_t *stats_btn)
{
    if (object_on_hover(stats_btn, &just_check) && scene->player->PAUSE &&
    !object_on_hover(scene->stats->lock, &just_check)) {
        object_set_rect(stats_btn, (sfIntRect){257, 0, 257, 20});
        if (scene->mouse_press) {
            scene->mouse_press = false;
            scene->stats->active = true;
        }
    } else if (scene->player->PAUSE) {
        object_set_rect(stats_btn, (sfIntRect){0, 0, 257, 20});
    }
}

void shape_stats(game *scene)
{
    object_t *stats = object_get_from_uuid(&scene->objects, PLAYER_STATS);
    float height = object_get_rect(stats).height;

    if (scene->stats->active) {
        if (height < 400)
            object_set_rect(stats, (sfIntRect){0, 0, 257, height + (
                0.001 * ENGINE->delta_time)});
    } else if (height > 0 && !scene->stats->active)
            object_set_rect(stats, (sfIntRect){0, 0, 257, height - (
                0.001 * ENGINE->delta_time)});
    if (height - (0.001 * ENGINE->delta_time) < 0 && !scene->stats->active)
        object_set_rect(stats, (sfIntRect){0, 0, 257, 0});
}

void stats_text(game *scene)
{
    textobject_t *maxpv = TGFU(&scene->objects, STATS_MAXPV_TXT);
    textobject_t *damage = TGFU(&scene->objects, STATS_DAMAGE_TXT);
    textobject_t *speed = TGFU(&scene->objects, STATS_SPEED_TXT);
    float height = object_get_rect(object_get_from_uuid(
        &scene->objects, PLAYER_STATS)).height;

    update_stats(scene);
    if (height > 140)
        object_set_visible(maxpv->object, true);
    else
        object_set_visible(maxpv->object, false);
    if (height > 240)
        object_set_visible(damage->object, true);
    else
        object_set_visible(damage->object, false);
    if (height > 340)
        object_set_visible(speed->object, true);
    else
        object_set_visible(speed->object, false);
}

void udpate_player_stats(game *scene)
{
    object_t *stats_btn = object_get_from_uuid(
        &scene->objects, PLAYER_STATS_BTN);

    if (scene->menu->active)
        return;
    stats_text(scene);
    shape_stats(scene);
    if (!scene->player->PAUSE && !scene->stats->is_lock) {
        object_set_rect(stats_btn, (sfIntRect){0, 0, 257, 20});
        scene->stats->active = false;
    }
    if (scene->stats->active )
        btn_active(scene, stats_btn);
    else
        btn_deactive(scene, stats_btn);
}
