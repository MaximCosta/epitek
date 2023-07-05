/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** selected_difficulty.c
*/

#include "../../../../../include/game/rpg.h"

void just_check(object_t *object);

object_t *difficulty_on_hover(object_t **list, MenuScene *scene, int p)
{
    object_t *save = NULL;

    for (int i = 0; list[i] != NULL; i++) {
        if (object_on_hover(list[i], &just_check) && save == NULL) {
            object_set_rect(list[i],
                (sfIntRect){(object_get_origin_size(list[i]).x / 3) * p, 0,
                    object_get_origin_size(list[i]).x / 3,
                    object_get_origin_size(list[i]).y});
            save = list[i];
        } else
            object_set_rect(list[i],
                (sfIntRect){0, 0, object_get_origin_size(list[i]).x / 3,
                    object_get_origin_size(list[i]).y});
    }
    return save;
}

void execute_action(MenuScene *scene, object_t *get, bool *fade_out, int lv)
{
    if (get->uuid == BACK_TO_MENU) {
        scene->mouse_press = false;
        scene->reverse = 1;
    } else {
        transaction(4 - (lv + 1));
        scene->mouse_press = false;
        scene->reverse = 2;
    }
}

void get_difficulty(
    MenuScene *scene, bool *fade_out, object_t **list, DeltaTime *delta)
{
    object_t *cursor = GET_OBJ(&scene->objects, CURSOR_M);
    object_t *get = list[5];
    int i = 0;

    for (; list[i] != get; i++);
    if (scene->mouse_press && get != NULL) {
        get = difficulty_on_hover(
            (object_t *[6]){list[0], list[1], list[2], list[3], list[4], NULL},
            scene, 2);
        if (elapsed_time_milliseconds(50, &delta->time, &delta->saved)
            && object_get_rect(cursor).left
                < object_get_origin_size(cursor).x - 47)
            object_set_rect(cursor,
                (sfIntRect){object_get_rect(cursor).left + 47, 0, 48, 48});
        if (object_get_rect(cursor).left
            >= object_get_origin_size(cursor).x - 47)
            execute_action(scene, get, fade_out, i);
        return;
    }
    if (get == NULL)
        object_set_rect(cursor, (sfIntRect){0, 0, 32, 32});
    else
        object_set_rect(cursor, (sfIntRect){32, 0, 48, 48});
}

void selected_difficulty(MenuScene *scene, bool *fade_out)
{
    object_t *peaceful;
    object_t *normal;
    object_t *hard;
    object_t *permanent;
    object_t *get;
    object_t *back;
    static DeltaTime delta = (DeltaTime){.saved = 0.00, .time = 0.00};

    if (!*fade_out)
        return;
    peaceful = GET_OBJ(&scene->objects, PEACEFUL);
    normal = GET_OBJ(&scene->objects, NORMAL);
    hard = GET_OBJ(&scene->objects, HARD);
    permanent = GET_OBJ(&scene->objects, PERMANENT);
    back = GET_OBJ(&scene->objects, BACK_TO_MENU);
    get = difficulty_on_hover(
        (object_t *[6]){peaceful, normal, hard, permanent, back, NULL}, scene,
        1);
    get_difficulty(scene, fade_out,
        (object_t *[6]){peaceful, normal, hard, permanent, back, get}, &delta);
}
