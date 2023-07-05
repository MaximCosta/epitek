/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** play_button.c
*/

#include "../../../../../include/game/rpg.h"

void on_hover_rect_tree(object_t *object);

void on_unhover_rect_tree(object_t *object);

void just_check(object_t *object);

void button_settings_nopress(object_t **list)
{
    if (object_on_hover(list[0], &just_check)) {
        on_hover_rect_tree(list[0]);
        object_set_rect(list[3], (sfIntRect){32, 0, 48, 48});
    }
    object_on_unhover(list[0], &on_unhover_rect_tree);
    if (object_on_hover(list[1], &just_check)) {
        on_hover_rect_tree(list[1]);
        object_set_rect(list[3], (sfIntRect){32, 0, 48, 48});
    }
    object_on_unhover(list[1], &on_unhover_rect_tree);
    if (object_on_hover(list[2], &on_hover_rect_tree)) {
        on_hover_rect_tree(list[2]);
        object_set_rect(list[3], (sfIntRect){32, 0, 48, 48});
    }
    object_on_unhover(list[2], &on_unhover_rect_tree);
}

void set_action(MenuScene *scene, object_t *get)
{
    object_t *cursor = GET_OBJ(&scene->objects, CURSOR_M)

    if (object_get_rect(cursor).left < object_get_origin_size(cursor).x- 47)
        return;
    if (get->uuid == PLAY_BUTTON)
        scene->slected_difficulty = true;
    if (get->uuid == MULTIPLAYER_BUTTON)
        scene->selected_htp = true;
    if (get->uuid == BACK_TO_MENU)
        scene_change(SHELL);
}

bool button_setitngs_is_press(object_t **list, MenuScene *scene)
{
    bool hover = false;

    for (int i = 0; list[i]; i++) {
        if (list[i]->uuid == CURSOR_M)
            continue;
        if (object_on_hover(list[i], &just_check)) {object_set_rect(
            list[i],
            (sfIntRect){(object_get_origin_size(list[i]).x / 3) * 2, 0,
            object_get_origin_size(list[i]).x / 3, object_get_size(
            list[i]).y});
            set_action(scene, list[i]);
            hover = true;
        }
    }
    return hover;
}

void button_settings(MenuScene *scene, object_t *cursor)
{
    object_t *play_button = object_get_from_uuid(&scene->objects, PLAY_BUTTON);
    object_t *multi_button = object_get_from_uuid(&scene->objects,
    MULTIPLAYER_BUTTON);
    object_t *back_button = object_get_from_uuid(&scene->objects, BACK_TO_MENU);
    static DeltaTime delta = (DeltaTime){.saved = 0.00, .time = 0.00};

    if (!scene->mouse_press) {
        object_set_rect(cursor, (sfIntRect){0, 0, 32, 32});
        button_settings_nopress((object_t *[4]){play_button, multi_button,
        back_button, cursor});
    }
    if (scene->mouse_press) {
        if (button_setitngs_is_press((object_t *[5]){play_button, multi_button,
        back_button, cursor, NULL}, scene) && elapsed_time_milliseconds(50,
        &delta.time, &delta.saved) && object_get_rect(cursor).left <
        object_get_origin_size(cursor).x - 47)
            object_set_rect(cursor, (sfIntRect){object_get_rect(cursor).left
            + 47, 0, 48, 48});
    }
}
