/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** trader_rect_animation.c
*/

#include "../../../../../include/game/rpg.h"

#define SPEED (0.001 * ENGINE->delta_time)

void just_check(object_t *object);

bool mouse_insides(object_t *object, sfIntRect rect)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(ENGINE->window);
    sfVector2f obj_pos = object_get_position(object);

    if ((mouse_pos.x >= obj_pos.x && mouse_pos.x <=
    obj_pos.x + rect.width) &&
    (mouse_pos.y >= obj_pos.y && mouse_pos.y <=
    obj_pos.y + rect.height))
        return true;
    return false;
}

bool perfect_this(sfIntRect rect, object_t *info_btn, sfIntRect n_rect,
game *scene)
{
    static bool active = false;

    if (rect.height >= 124 && mouse_insides(info_btn, n_rect)) {
        object_set_rect(info_btn, (sfIntRect){rect.left, rect.top, rect.width,
        124});
        if (scene->mouse_press && !active) {
            active = true;
            scene->mouse_press = false;
        } else if (scene->mouse_press && active) {
            active = false;
            scene->mouse_press = false;
        }
    }
    if (!mouse_insides(info_btn, n_rect) && rect.height <= 5)
        object_set_rect(info_btn, (sfIntRect){rect.left, rect.top, rect.width,
        0});
    return active;
}

void trader_info(game *scene, bool active)
{
    object_t *info = object_get_from_uuid(&scene->objects, TRADER_INFO);
    sfIntRect rect = object_get_rect(info);

    if (active && rect.height < 640)
        object_set_rect(info, (sfIntRect){rect.left, rect.top, rect.width,
        rect.height + SPEED});
    if (!active && rect.height > 0)
        object_set_rect(info, (sfIntRect){rect.left, rect.top, rect.width,
        rect.height - SPEED});
    if (active && rect.height >= 640)
        object_set_rect(info, (sfIntRect){rect.left, rect.top, rect.width,
        640});
    if (!active && rect.height <= 0)
        object_set_rect(info, (sfIntRect){rect.left, rect.top, rect.width, 0});
}

void update_info_btn(game *scene, object_t *info_btn)
{
    sfIntRect rect = object_get_rect(info_btn);
    sfIntRect n_rect = rect;
    static bool active = false;

    n_rect.height = 124;
    if (mouse_insides(info_btn, n_rect) && rect.height < 124) {
        object_set_rect(info_btn, (sfIntRect){rect.left, rect.top, rect.width,
        rect.height + SPEED});
    } else if (!mouse_insides(info_btn, n_rect) && rect.height > 0)
        object_set_rect(info_btn, (sfIntRect){rect.left, rect.top, rect.width,
        rect.height - SPEED});
    active = perfect_this(rect, info_btn, n_rect, scene);
    trader_info(scene, active);
}

void trader_update_rec(game *scene, textobject_t *wallet, V2F wallet_p,
V2F pos)
{
    object_t *inf_btn = object_get_from_uuid(&scene->objects, TRADER_INFO_BTN);
    object_t *info = object_get_from_uuid(&scene->objects, TRADER_INFO);
    V2F inf_btn_p = object_get_position(inf_btn);
    V2F info_p = object_get_position(info);

    if (scene->trader->active && pos.x > 1920) {
        OSP(scene->trader->trader_panel, (V2F){pos.x - SPEED, pos.y});
        TSP(wallet, (V2F){wallet_p.x - SPEED, wallet_p.y});
        OSP(inf_btn, (V2F){inf_btn_p.x - SPEED, inf_btn_p.y});
        OSP(info, (V2F){info_p.x - SPEED, info_p.y});
    }
    else if (!scene->trader->active && pos.x < 2421) {
        OSP(scene->trader->trader_panel, (V2F){pos.x + SPEED, pos.y});
        TSP(wallet, (V2F){wallet_p.x + SPEED, wallet_p.y});
        OSP(inf_btn, (V2F){inf_btn_p.x + SPEED, inf_btn_p.y});
        OSP(info, (V2F){info_p.x + SPEED, info_p.y});
    }
    update_info_btn(scene, inf_btn);
}
