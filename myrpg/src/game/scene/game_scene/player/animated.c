/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** animated.c
*/

#include "../../../../../include/game/rpg.h"

void hit_animated(game *scene, object_t *player)
{
    static DeltaTime delta = (DeltaTime){.saved = 0.00, .time = 0.00};

    if (!scene->player->HIT || scene->toolbar->pv <= 0)
        return;
    if (object_get_rect(player).top >= 128) {
        object_set_rect(player, (sfIntRect){640, 0, 128, 64});
        scene->player->HIT = false;
    }
    if (elapsed_time_milliseconds(50, &delta.time, &delta.saved))
        object_set_rect(player, (sfIntRect){640,
        object_get_rect(player).top + 64, 128, 64});
}

void run_animated(game *scene, object_t *player)
{
    static DeltaTime delta = (DeltaTime){.saved = 0.00, .time = 0.00};

    if (!scene->player->DOWN && !scene->player->UP && !scene->player->LEFT &&
    !scene->player->RIGHT)
        return;
    if (scene->player->DASH || scene->player->JETPACK || scene->player->HIT)
        return;
    if (elapsed_time_milliseconds(50, &delta.time, &delta.saved))
        object_set_rect(player, (sfIntRect){0,
        object_get_rect(player).top + 64, 128, 64});
    if (object_get_rect(player).top >= 704)
        object_set_rect(player, (sfIntRect){0, 0, 128, 64});

}

void idle_animated(game *scene, object_t *player)
{
    if (scene->player->DASH || scene->player->JETPACK || scene->player->HIT)
        return;
    object_set_rect(player, (sfIntRect){128, 0, 128, 64});
}

void jetpack_animated(game *scene, object_t *player)
{
    static DeltaTime delta = (DeltaTime){.saved = 0.00, .time = 0.00};

    if (scene->player->DASH || !scene->player->JETPACK || scene->player->HIT)
        return;
    if (elapsed_time_milliseconds(50, &delta.time, &delta.saved)) {
        object_set_rect(player, (sfIntRect){512,
        object_get_rect(player).top + 64, 128, 64});
        scene->jet_power -= 1;
    }
    if (object_get_rect(player).top >= 320)
        object_set_rect(player, (sfIntRect){512, 0, 128, 64});
}
