/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** test_colide.c
*/

#include "../../../../include/game/rpg.h"

int test_colide(object_t *obj, object_t *other)
{
    sfIntRect rect = object_get_rect(obj);
    sfIntRect other_rect = object_get_rect(other);
    sfVector2f pos = object_get_position(obj);
    sfVector2f other_pos = object_get_position(other);

    rect.left = pos.x;
    rect.top = pos.y;
    other_rect.left = other_pos.x;
    other_rect.top = other_pos.y + 100;
    return rect.left + rect.width >= other_rect.left &&
            rect.left <= other_rect.left + other_rect.width &&
            rect.top + rect.height >= other_rect.top &&
            rect.top <= other_rect.top + other_rect.height;
}