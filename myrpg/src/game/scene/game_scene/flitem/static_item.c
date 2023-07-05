/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** static_item.c
*/

#include "../../../../../include/game/rpg.h"

void static_left_item(game *enmy, float speed, object_t *item)
{
    object_set_position(item, (sfVector2f){
    object_get_position(item).x + (speed * ENGINE->delta_time),
    object_get_position(item).y});
}

void static_right_item(game *enmy, float speed, object_t *item)
{
    object_set_position(item, (sfVector2f){
    object_get_position(item).x - (speed * ENGINE->delta_time),
    object_get_position(item).y});
}

void static_down_item(game *enmy, float speed, object_t *item)
{
    object_set_position(item, (sfVector2f){object_get_position(item).x,
    object_get_position(item).y - (speed * ENGINE->delta_time)});
}

void static_up_item(game *enmy, float speed, object_t *item)
{
    object_set_position(item, (sfVector2f){object_get_position(item).x,
    object_get_position(item).y + (speed * ENGINE->delta_time)});
}

void static_item(game *scene, float speed, char *move)
{
    flitem_t *tmp = scene->flitem;

    for (; tmp != NULL; tmp = tmp->next) {
        if (equal(move, "LEFT"))
            static_left_item(scene, speed, tmp->data->item);
        if (equal(move, "RIGHT"))
            static_right_item(scene, speed, tmp->data->item);
        if (equal(move, "DOWN"))
            static_down_item(scene, speed, tmp->data->item);
        if (equal(move, "UP"))
            static_up_item(scene, speed, tmp->data->item);
        tmp->data->initial_pos = object_get_position(tmp->data->item).y;
    }
}
