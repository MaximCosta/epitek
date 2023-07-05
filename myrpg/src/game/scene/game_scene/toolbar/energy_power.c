/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** energy_power.c
*/

#include "../../../../../include/game/rpg.h"

void energy_power(game *scene)
{
    static DeltaTime delta = {.time = 0.00, .saved = 0.00};
    float percent = (float) scene->energy_power / 100;

    if (scene->energy_power <= 0 && scene->player->ENERGY_ATTACK) {
        scene->player->ENERGY_ATTACK = false;
        scene->energy_power = -20;
    }
    if (scene->energy_power >= 0)
        object_set_scale(scene->toolbar->actions[3], (sfVector2f){1, percent});
    if (scene->energy_power < 100 && elapsed_time_milliseconds(200,
    &delta.time, &delta.saved) && !scene->player->PAUSE &&
    !scene->player->ENERGY_ATTACK)
        scene->energy_power += 1;
    else if (scene->energy_power == 100)
        object_set_scale(scene->toolbar->actions[3], (sfVector2f){0, 0});
}
