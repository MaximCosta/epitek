/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** event.c
*/

#include "../../../../../include/game/rpg.h"

void clip(mob_t *tmp, sfFloatRect mob_rect)
{
    if (!equal(tmp->data->state, "HIT")) {
        object_set_rect(tmp->mob, (sfIntRect){mob_rect.left, 0,
        mob_rect.width, mob_rect.height});
        tmp->data->state = my_strdup("HIT");
    }
}

void send_damage(game *scene, int step, int damage, int this_step)
{
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);
    mob_t *tmp = scene->mobs;
    sfFloatRect player_rect = sfSprite_getGlobalBounds(player->sprite);
    sfFloatRect mob_rect;

    if (step != this_step)
        return;
    for (; tmp != NULL; tmp = tmp->next) {
        mob_rect = sfSprite_getGlobalBounds(tmp->mob->sprite);
        if (sfFloatRect_intersects(&player_rect, &mob_rect, NULL) == sfTrue) {
            tmp->data->pv -= damage;
            clip(tmp, mob_rect);
        }
    }
}

void attack_event(game *scene)
{
    static DeltaTime delta = (DeltaTime){.saved = 0.00, .time = 0.00};
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);
    static int step = 0;

    if (elapsed_time_milliseconds(50, &delta.time, &delta.saved)) {
        object_set_rect(player, (sfIntRect){1536, object_get_rect(player).top
        + 64, 128, 64});
        send_damage(scene, step, scene->player->damage, 4);
        step++;
    }
    if (object_get_rect(player).top >= 576) {
        scene->player->ATTACK = false;
        step = 0;
    }
}

void energy_attack_event(game *scene)
{
    static DeltaTime delta = (DeltaTime){.saved = 0.00, .time = 0.00};
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);
    static int step = 0;

    if (elapsed_time_milliseconds(50, &delta.time, &delta.saved)) {
        object_set_rect(player, (sfIntRect){384, object_get_rect(player).top
        + 64, 128, 64});
        scene->energy_power -= 5;
        send_damage(scene, step, scene->player->energy_damage, 9);
        step++;
    }
    if (object_get_rect(player).top >= 896) {
        scene->player->ENERGY_ATTACK = false;
        step = 0;
    }
}

void player_event(game *scene)
{
    if (scene->player->ATTACK && !scene->player->PAUSE &&
    !scene->player->JETPACK
    && !scene->player->ENERGY_ATTACK)
        attack_event(scene);
    if (scene->player->ENERGY_ATTACK && !scene->player->PAUSE &&
    !scene->player->JETPACK && !scene->player->ATTACK)
        energy_attack_event(scene);

}
