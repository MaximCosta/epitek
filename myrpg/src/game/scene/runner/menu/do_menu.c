/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** do_menu.c
*/

#include "../../../../../include/game/rpg.h"

void runner_do_menu(runner_t *runner)
{
    runner_menu_t *menu = runner->menu;
    object_t *obj = object_get_from_uuid(&menu->obj, 69);
    object_t *obj2 = object_get_from_uuid(&menu->obj, 70);

    if (!object_is_hovered(obj))
        sfSprite_setColor(obj->sprite, sfColor_fromRGB(255, 255, 255));
    if (!object_is_hovered(obj2))
        sfSprite_setColor(obj2->sprite, sfColor_fromRGB(255, 255, 255));
}