/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** static_enemy.c
*/

#include "../../../../../include/game/rpg.h"

void static_item(game *scene, float speed, char *move);
void static_trader(game *scene, float speed, char *move);

void static_left(game *enmy, float speed, object_t *mob)
{
    object_set_position(mob, (sfVector2f){
    object_get_position(mob).x + (speed * ENGINE->delta_time),
    object_get_position(mob).y});
}

void static_right(game *enmy, float speed, object_t *mob)
{
    object_set_position(mob, (sfVector2f){
    object_get_position(mob).x - (speed * ENGINE->delta_time),
    object_get_position(mob).y});
}

void static_down(game *enmy, float speed, object_t *mob)
{
    object_set_position(mob, (sfVector2f){object_get_position(mob).x,
    object_get_position(mob).y - (speed * ENGINE->delta_time)});
}

void static_up(game *enmy, float speed, object_t *mob)
{
    object_set_position(mob, (sfVector2f){object_get_position(mob).x,
    object_get_position(mob).y + (speed * ENGINE->delta_time)});
}

void static_enemy(game *scene, float speed, char *move)
{
    mob_t *tmp = scene->mobs;

    static_item(scene, speed, move);
    static_trader(scene, speed, move);
    for (; tmp != NULL; tmp = tmp->next) {
        if (equal(move, "LEFT"))
            static_left(scene, speed, tmp->mob);
        if (equal(move, "RIGHT"))
            static_right(scene, speed, tmp->mob);
        if (equal(move, "DOWN"))
            static_down(scene, speed, tmp->mob);
        if (equal(move, "UP"))
            static_up(scene, speed, tmp->mob);
    }
}
