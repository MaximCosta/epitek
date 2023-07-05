/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** update_gui.c
*/

#include "../../../../../include/game/rpg.h"

void just_check(object_t *object);

void update_gui_profile(game *scene)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(ENGINE->window);
    object_t *profile_o = object_get_from_uuid(&scene->objects, PLAYER_ICON);
    object_t *profile_gui_o =
        object_get_from_uuid(&scene->objects, PLAYER_PROFILE_GUI);
    object_t *profile_gui_edit_name_o =
        object_get_from_uuid(&scene->objects, PLAYER_PROFILE_GUI_NAME_EDIT);
    object_t *player_skin_o =
        object_get_from_uuid(&scene->objects, PLAYER_PROFILE_GUI_PLAYER);

    if (object_on_hover(profile_o, &just_check) && scene->player->PAUSE
    && !scene->menu->active) {
        object_set_rect(profile_o, (sfIntRect){48, 0, 48, 48});
        if (scene->mouse_press && scene->player->PAUSE) {
            scene->player->INVENTORY_O = false;
            scene->mouse_press = false;
            if (scene->player->is_profile_gui_opened)
                scene->player->is_profile_gui_opened = false;
            else
                scene->player->is_profile_gui_opened = true;
        }
    } else {
        if (!scene->player->PAUSE)
            scene->player->is_profile_gui_opened = false;
        object_set_rect(profile_o, (sfIntRect){0, 0, 48, 48});
    }
    if (object_on_hover(profile_gui_edit_name_o, &just_check)
        && scene->player->PAUSE) {
        object_set_rect(profile_gui_edit_name_o, (sfIntRect){391, 0, 391, 24});
    } else {
        object_set_rect(profile_gui_edit_name_o, (sfIntRect){0, 0, 391, 24});
    }
    if (scene->player->is_profile_gui_opened) {
        if (m.x >= 948 - 208 && m.x <= 948 + 208 && m.y >= 784 - 208
            && m.y <= 784 + 208 && scene->mouse_press) {
            m.x -= 948;
            m.y -= 784;
            if (m.x < -208)
                m.x = -208;
            if (m.y < -208)
                m.y = -208;
            if (m.x > 208)
                m.x = 208;
            if (m.y > 208)
                m.y = 208;

            sfColor color =
                sfImage_getPixel(scene->color_palette, m.x + 208, m.y + 208);

            color.a = 255;
            sfSprite_setColor(player_skin_o->sprite, color);
            sfSprite_setColor(
                object_get_from_uuid(&scene->objects, PLAYER)->sprite, color);
        }
        object_set_visible(profile_gui_o, true);
        object_set_visible(profile_gui_edit_name_o, true);
        object_set_visible(player_skin_o, true);
    } else {
        object_set_visible(profile_gui_o, false);
        object_set_visible(profile_gui_edit_name_o, false);
        object_set_visible(player_skin_o, false);
    }
}