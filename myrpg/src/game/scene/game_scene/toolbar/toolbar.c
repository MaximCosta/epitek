/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** toolbar.c
*/

#include "../../../../../include/game/rpg.h"

void energy_power(game *scene);

void toolbar_action_x(game *scene, int i, bool live, float speed)
{
    if (object_get_scale(scene->toolbar->actions[i]).x < 1)
        object_set_scale(scene->toolbar->actions[i],
        (sfVector2f){object_get_scale(scene->toolbar->actions[i]).x
        + (speed * ENGINE->delta_time), 1});
    else if (object_get_scale(scene->toolbar->actions[i]).x >= 1 && live)
        object_set_scale(scene->toolbar->actions[i], (sfVector2f){1, 1});
    if (!live)
        object_set_scale(scene->toolbar->actions[i], (sfVector2f){0, 1});
}

void toolbar_action_y(game *scene, int i, bool live, float speed)
{
    if (object_get_scale(scene->toolbar->actions[i]).y > 0)
        object_set_scale(scene->toolbar->actions[i],
        (sfVector2f){1, object_get_scale(scene->toolbar->actions[i]).y
        - (speed * ENGINE->delta_time)});
    else if (object_get_scale(scene->toolbar->actions[i]).y <= 0 && live)
        object_set_scale(scene->toolbar->actions[i], (sfVector2f){1, 0});
    if (!live)
        object_set_scale(scene->toolbar->actions[i], (sfVector2f){0, 1});
}

void jet_power(game *scene)
{
    static DeltaTime delta = {.time = 0.00, .saved = 0.00};
    float percent = (float) scene->jet_power / 100;

    if (scene->jet_power <= 0 && scene->player->JETPACK) {
        scene->player->JETPACK = false;
        scene->jet_power = -20;
    }
    if (scene->jet_power >= 0)
        object_set_scale(scene->toolbar->actions[2], (sfVector2f){1, percent});
    if (scene->jet_power < 100 && elapsed_time_milliseconds(100, &delta.time,
    &delta.saved) && !scene->player->PAUSE && !scene->player->JETPACK)
        scene->jet_power += 1;
    else if (scene->jet_power == 100)
        object_set_scale(scene->toolbar->actions[2], (sfVector2f){0, 0});
}

void update_toolbar(game *scene)
{
    toolbar_action_x(scene, 0, scene->player->ATTACK, 0.000003);
    toolbar_action_x(scene, 1, scene->player->DASH, 0.000002);
    jet_power(scene);
    energy_power(scene);
}

void update_gui(game *scene)
{
    object_t *pv = object_get_from_uuid(&scene->objects, PV);
    sfVector2f pv_scale = object_get_scale(pv);
    float pv_percent = (float) (scene->toolbar->pv * 100);

    pv_percent = (float) pv_percent / scene->player->pv_max;
    pv_percent /= 100;
    if (pv_scale.x < pv_percent)
        object_set_scale(pv, (sfVector2f){pv_scale.x +
        (0.0000005 * ENGINE->delta_time), 1});
    if (pv_scale.x > pv_percent)
        object_set_scale(pv, (sfVector2f){pv_scale.x -
        (0.0000005 * ENGINE->delta_time), 1});
    update_toolbar(scene);

}
