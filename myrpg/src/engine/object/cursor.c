/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** cursor.c
*/

#include "../../../include/engine/engine.h"

void follow_mouse(object_t *object)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(ENGINE->window);
    sfVector2f object_size;

    if (!object)
        return;
    object_size.x = object_get_rect(object).width;
    object_size.y = object_get_rect(object).height;
    object_set_position(object,
        (sfVector2f){mouse_pos.x - (object_size.x / 2),
            mouse_pos.y - (object_size.y / 2)});
}

void disable_cursor(void)
{
    sfRenderWindow_setMouseCursorVisible(ENGINE->window, sfFalse);
}
