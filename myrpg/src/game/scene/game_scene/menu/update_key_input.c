/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** update_key_input.c
*/

#include "../../../../../include/game/rpg.h"

void set_btn_visible(game *scene, sfColor color, object_t *object);
void just_check(object_t *object);
void change_input_key(game *scene);
bool update_menu_btn(game *scene, object_t *object);

void btn_input(game *scene, object_t *object, sfText *text)
{
    const sfTexture *texture = sfSprite_getTexture(object->sprite);
    sfVector2u st = sfTexture_getSize(texture);

    if (!scene->menu->active)
        return;
    if (object_on_hover(object, &just_check)) {
        sfText_setColor(text, sfBlack);
        OSR(object, (sfIntRect){st.x / 2, 0, st.x / 2, st.y});
        if (scene->mouse_press) {
            scene->mouse_press = false;
            scene->menu->edit_key = true;
            scene->menu->edit = object->uuid;
        }
    } else {
        sfText_setColor(text, sfWhite);
        OSR(object, (sfIntRect){0, 0, st.x / 2, st.y});
    }
}

void update_key_input(game *scene, menu_t *menu, sfColor color)
{
    set_btn_visible(scene, color, menu->right_o);
    set_btn_visible(scene, color, menu->left_o);
    set_btn_visible(scene, color, menu->up_o);
    set_btn_visible(scene, color, menu->down_o);
    set_btn_visible(scene, color, menu->interact_o);
    set_btn_visible(scene, color, menu->inventory_o);
    set_btn_visible(scene, color, menu->dash_o);
    set_btn_visible(scene, color, menu->jetpack_o);
    set_btn_visible(scene, color, menu->invincibility);
    set_btn_visible(scene, color, menu->auto_save);
    set_btn_visible(scene, color, OGFuuid_t(&scene->objects, FPS_SLIDER));
    set_btn_visible(scene, color, TOGFUUID(&scene->objects, TEXT_FPS)->object);
    set_btn_visible(scene, color, OGFuuid_t(&scene->objects, VOLUME_SLIDER));
    set_btn_visible(scene, color, TOGFUUID(&scene->objects,
    TEXT_VOLUME)->object);
}

void btn_checker(game *scene, menu_t *menu)
{
    if (object_on_hover(menu->invincibility, &just_check) &&
    scene->mouse_press) {
        if (object_get_rect(menu->invincibility).left == 0)
            object_set_rect(menu->invincibility, (sfIntRect){30, 0, 30, 30});
        else
            object_set_rect(menu->invincibility, (sfIntRect){0, 0, 30, 30});
        scene->mouse_press = false;
    }
    if (object_on_hover(menu->auto_save, &just_check) &&
    scene->mouse_press) {
        if (object_get_rect(menu->auto_save).left == 0)
            object_set_rect(menu->auto_save, (sfIntRect){30, 0, 30, 30});
        else
            object_set_rect(menu->auto_save, (sfIntRect){0, 0, 30, 30});
        scene->mouse_press = false;
    }
}

void update_key_input_btn(game *scene, menu_t *menu)
{
    btn_input(scene, menu->right_o, menu->right_key->text);
    btn_input(scene, menu->left_o, menu->left_key->text);
    btn_input(scene, menu->up_o, menu->up_key->text);
    btn_input(scene, menu->down_o, menu->down_key->text);
    btn_input(scene, menu->interact_o, menu->interact_key->text);
    btn_input(scene, menu->inventory_o, menu->inventory_key->text);
    btn_input(scene, menu->dash_o, menu->dash_key->text);
    btn_input(scene, menu->jetpack_o, menu->jetpack_key->text);
    btn_checker(scene, scene->menu);
}
