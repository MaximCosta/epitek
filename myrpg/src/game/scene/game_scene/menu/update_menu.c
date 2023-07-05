/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** update_menu.c
*/

#include "../../../../../include/game/rpg.h"

void just_check(object_t *object);
void update_key_input(game *scene, menu_t *menu, sfColor color);
void update_key_input_btn(game *scene, menu_t *menu);
void update_any_key(game *scene);
void all_slider(game *scene);

void set_btn_visible(game *scene, sfColor color, object_t *object)
{
    sfSprite_setColor(object->sprite, color);
    if (color.a <= 0)
        object_set_visible(object, false);
    else
        object_set_visible(object, true);
}

void all_visible_transition(game *scene, object_t *menu, sfColor color)
{
    set_btn_visible(scene, color, menu);
    set_btn_visible(scene, color, scene->menu->resume);
    set_btn_visible(scene, color, scene->menu->restart);
    set_btn_visible(scene, color, scene->menu->leave);
    set_btn_visible(scene, color, scene->menu->back_to_menu);
    set_btn_visible(scene, color, scene->menu->save);
    set_btn_visible(scene, color, scene->menu->right_key->object);
    set_btn_visible(scene, color, scene->menu->left_key->object);
    set_btn_visible(scene, color, scene->menu->up_key->object);
    set_btn_visible(scene, color, scene->menu->down_key->object);
    set_btn_visible(scene, color, scene->menu->interact_key->object);
    set_btn_visible(scene, color, scene->menu->inventory_key->object);
    set_btn_visible(scene, color, scene->menu->dash_key->object);
    set_btn_visible(scene, color, scene->menu->jetpack_key->object);
    update_key_input(scene, scene->menu, color);
}

void animation_menu(game *scene, object_t *menu)
{
    static sfColor color = {255, 255, 255, 0};
    float speed = 0.0005 * ENGINE->delta_time;

    if (scene->menu->active && color.a < 240) {
        color.a += speed;
    } else if (color.a > 10 && !scene->menu->active)
        color.a -= speed;
    if (color.a >= 240 && scene->menu->active)
        color.a = 255;
    if (color.a <= 10 && !scene->menu->active)
        color.a = 0;
    all_visible_transition(scene, menu, color);
}

bool update_menu_btn(game *scene, object_t *object)
{
    const sfTexture *texture = sfSprite_getTexture(object->sprite);
    sfVector2u st = sfTexture_getSize(texture);

    if (!scene->menu->active)
        return false;
    if (object_on_hover(object, &just_check)) {
        OSR(object, (sfIntRect){st.x / 2, 0, st.x / 2, st.y});
        if (scene->mouse_press) {
            scene->mouse_press = false;
            return true;
        }
    } else
        OSR(object, (sfIntRect){0, 0, st.x / 2, st.y});
    return false;
}

void update_menu(game *scene)
{
    object_t *menu = OGFuuid_t(&scene->objects, SETTINGS_MENU);

    animation_menu(scene, menu);
    update_menu_btn(scene, scene->menu->save);
    if (update_menu_btn(scene, scene->menu->resume)) {
        scene->menu->active = false;
        scene->player->PAUSE = false;
    }
    if (update_menu_btn(scene, scene->menu->back_to_menu))
        scene_change(MAIN_SCENE);
    if (update_menu_btn(scene, scene->menu->leave))
        scene_change(SHELL);
    update_menu_btn(scene, scene->menu->restart);
    update_key_input_btn(scene, scene->menu);
    update_any_key(scene);
    all_slider(scene);
}
