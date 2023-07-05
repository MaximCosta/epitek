/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** ia_animation.c
*/

#include "../../../../../include/game/rpg.h"

bool ia_add_pv(game *scene, mob_t *tmp_sh, mob_t *mobs);

void ia_idle(game *scene, object_t *mob, enemy_t *data)
{
    float left = data->dimension.x * 2;

    if (elapsed_time_milliseconds(
            data->delay, &data->delta.time, &data->delta.saved))
        object_set_rect(mob,
            (sfIntRect){left, object_get_rect(mob).top + data->dimension.y,
                data->dimension.x, data->dimension.y});
    if (object_get_rect(mob).top >= data->top_idle)
        object_set_rect(
            mob, (sfIntRect){left, 0, data->dimension.x, data->dimension.y});
}

void ia_target(game *scene, object_t *mob, enemy_t *data)
{
    float left = data->dimension.x * 3;

    if (elapsed_time_milliseconds(
            data->delay, &data->delta.time, &data->delta.saved))
        object_set_rect(mob,
            (sfIntRect){left, object_get_rect(mob).top + data->dimension.y,
                data->dimension.x, data->dimension.y});
    if (object_get_rect(mob).top >= data->top_run)
        object_set_rect(
            mob, (sfIntRect){left, 0, data->dimension.x, data->dimension.y});
}

void get_step(int step, enemy_t *data, game *scene)
{
    if (scene->player->DASH ||
    object_get_rect(scene->menu->invincibility).left > 0)
        return;
    if (!scene->player->ATTACK && !scene->player->ENERGY_ATTACK)
        scene->player->HIT = true;
    if (equal(data->type, "BIG") && step == 4)
        scene->toolbar->pv -= data->damage;
    if (equal(data->type, "DROID") && (step == 0 || step == 2))
        scene->toolbar->pv -= data->damage;
    if (equal(data->type, "PHANTOM") && (step == 7 || step == 11))
        scene->toolbar->pv -= data->damage;
    if (scene->toolbar->pv < 0)
        scene->toolbar->pv = 0;
}

void ia_attack(game *scene, object_t *mob, enemy_t *data)
{
    float left = 0;
    static int step = 0;

    if (elapsed_time_milliseconds(
            data->delay, &data->delta.time, &data->delta.saved)) {
        object_set_rect(mob,
            (sfIntRect){left, object_get_rect(mob).top + data->dimension.y,
                data->dimension.x, data->dimension.y});
        get_step(step, data, scene);
        step++;
    }
    if (object_get_rect(mob).top >= data->top_attack) {
        object_set_rect(
            mob, (sfIntRect){left, 0, data->dimension.x, data->dimension.y});
        data->state = my_strdup("DETECTION");
        step = 0;
    }
}

bool ia_hit(game *scene, mob_t *mobs, mob_t *tmp_sh)
{
    float left = mobs->data->dimension.x;
    static int step = 0;

    if ((step >= 2 && mobs->data->pv > 0)
        || (object_get_rect(mobs->mob).top >= mobs->data->top_damage)) {
        mobs->data->state = my_strdup("DETECTION");
        step = 0;
        if (mobs->data->pv <= 0)
            ia_add_pv(scene, tmp_sh, mobs);
        object_set_rect(mobs->mob,
            (sfIntRect){
                left, 0, mobs->data->dimension.x, mobs->data->dimension.y});
        return false;
    }
    if (elapsed_time_milliseconds(
            100, &mobs->data->delta.time, &mobs->data->delta.saved)) {
        object_set_rect(mobs->mob,
            (sfIntRect){left,
                object_get_rect(mobs->mob).top + mobs->data->dimension.y,
                mobs->data->dimension.x, mobs->data->dimension.y});
        step++;
    }
    return false;
}
