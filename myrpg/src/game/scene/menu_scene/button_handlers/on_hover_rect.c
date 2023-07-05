/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** on_hover_rect.c
*/

#include "../../../../../include/game/rpg.h"

void just_check(object_t *object)
{
    return;
}

void on_hover_rect_tree(object_t *object)
{
    if (!object)
        return;
    object_set_rect(object, (sfIntRect){
        object_get_origin_size(object).x / 3, 0,
        object_get_origin_size(object).x / 3,
        object_get_size(object).y});
}

void on_unhover_rect_tree(object_t *object)
{
    if (!object)
        return;
    object_set_rect(object, (sfIntRect){0, 0,
        object_get_origin_size(object).x / 3,
        object_get_size(object).y});
}
