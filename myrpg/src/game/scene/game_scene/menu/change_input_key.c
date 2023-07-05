/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** change_input_key.c
*/

#include "../../../../../include/game/rpg.h"

void replace_all_input_other(game *scene, char *key)
{
    if (scene->menu->edit == M_JETPACK_O) {
        scene->key_input->jet_pack = scene->menu->input;
        TOSTR(scene->menu->jetpack_key, key);
    }
    if (scene->menu->edit == M_INVENTORY_O) {
        scene->key_input->inventory = scene->menu->input;
        TOSTR(scene->menu->inventory_key, key);
    }
    if (scene->menu->edit == M_INTERACT_O) {
        scene->key_input->interact = scene->menu->input;
        TOSTR(scene->menu->interact_key, key);
    }
    if (scene->menu->edit == M_DASH_O) {
        scene->key_input->dash = scene->menu->input;
        TOSTR(scene->menu->dash_key, key);
    }
}

char *key_hardcode(game *scene, char *key, int i)
{
    if (i == 60)
        key = my_strdup("TAB");
    if (i == 73)
        key = my_strdup("UP");
    if (i == 71)
        key = my_strdup("LEFT");
    if (i == 74)
        key = my_strdup("DOWN");
    if (i == 72)
        key = my_strdup("RIGHT");
    if (i == 38)
        key = my_strdup("SHIFT");
    if (i == 75)
        key = my_strdup("0");
    if (i > 75 && i <= 84)
        key = my_itoa(i - 75, 0);
    if (i == 57)
        key = my_strdup("SPACE");
    return key;
}

void replace_all_input(game *scene)
{
    char *key = my_strcat_char("", scene->menu->input + 97);

    key = key_hardcode(scene, key, scene->menu->input);
    if (scene->menu->edit == M_RIGHT_O) {
        scene->key_input->right = scene->menu->input;
        TOSTR(scene->menu->right_key, key);
    }
    if (scene->menu->edit == M_LEFT_O) {
        scene->key_input->left = scene->menu->input;
        TOSTR(scene->menu->left_key, key);
    }
    if (scene->menu->edit == M_UP_O) {
        scene->key_input->up = scene->menu->input;
        TOSTR(scene->menu->up_key, key);
    }
    if (scene->menu->edit == M_DOWN_O) {
        scene->key_input->down = scene->menu->input;
        TOSTR(scene->menu->down_key, key);
    }
    replace_all_input_other(scene, key);
    scene->menu->input = -1;
}

void center_text(game *scene, textobject_t *text)
{
    float pos = 1710;
    V2F o_pos = textobject_get_position(text);

    textobject_set_position(text,
    (V2F){pos - sfText_getGlobalBounds(text->text).width / 2.4, o_pos.y});
}

void update_any_key(game *scene)
{
    object_t *any = OGFuuid_t(&scene->objects, M_ANY_KEY);

    if(!scene->menu->active || !scene->menu->edit_key) {
        object_set_visible(any, false);
    } else
        object_set_visible(any, true);
    if (scene->menu->input < 0)
        return;
    replace_all_input(scene);
    center_text(scene, scene->menu->right_key);
    center_text(scene, scene->menu->left_key);
    center_text(scene, scene->menu->up_key);
    center_text(scene, scene->menu->down_key);
    center_text(scene, scene->menu->jetpack_key);
    center_text(scene, scene->menu->inventory_key);
    center_text(scene, scene->menu->interact_key);
    center_text(scene, scene->menu->dash_key);
}
