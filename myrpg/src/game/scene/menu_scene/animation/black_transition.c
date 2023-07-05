/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** black_transition.c
*/

#include "../../../../../include/game/rpg.h"

void black_transition(MenuScene *scene)
{
    object_t *black_screen = NULL;
    sfColor actual = sfColor_fromRGBA(255, 255, 255, 0);

    black_screen = GET_OBJ(&scene->objects, BLACKSCREEN_M);
    actual = sfSprite_getColor(black_screen->sprite);
    if (actual.a <= 10)
        return;
    actual.a -= (0.002 * ENGINE->delta_time / 5);
    sfSprite_setColor(black_screen->sprite, actual);
}

void add_reverse(MenuScene *scene)
{
    object_t *peaceful = GET_OBJ(&scene->objects, PEACEFUL);
    object_t *normal = GET_OBJ(&scene->objects, NORMAL);
    object_t *hard = GET_OBJ(&scene->objects, HARD);
    object_t *permanent = GET_OBJ(&scene->objects, PERMANENT);
    object_t *play_btn = GET_OBJ(&scene->objects, PLAY_BUTTON);
    object_t *multi_btn = GET_OBJ(&scene->objects, MULTIPLAYER_BUTTON);
    object_t *title = GET_OBJ(&scene->objects, TITLE);
    object_t *back = GET_OBJ(&scene->objects, BACK_TO_MENU);

    object_set_visible(peaceful, false);
    object_set_visible(normal, false);
    object_set_visible(hard, false);
    object_set_visible(permanent, false);
    object_set_visible(play_btn, true);
    object_set_visible(multi_btn, true);
    object_set_visible(title, true);
    object_set_position(back, (sfVector2f){538, 680});
    scene->selected = 0;
    scene->slected_difficulty = false;
    scene->reverse = 0;
}

void black_fade_out(MenuScene *scene, bool *fade_out)
{
    object_t *black_screen = NULL;
    sfColor actual = sfColor_fromRGBA(255, 255, 255, 0);

    if (scene->reverse == 0)
        if (!scene->slected_difficulty || *fade_out)
            return;
    black_screen = GET_OBJ(&scene->objects, BLACKSCREEN_M);
    actual = sfSprite_getColor(black_screen->sprite);
    actual.a += (0.0008 * ENGINE->delta_time);
    sfSprite_setColor(black_screen->sprite, actual);
    if (actual.a >= 200) {
        if (scene->reverse == 1) {
            *fade_out = false;
            add_reverse(scene);
            return;
        }
        if (scene->reverse == 2) {
            scene->reverse = 0;
            scene_change(SWITCH_SC);
            return;
        }
        *fade_out = true;
    }
}
