/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** fade_out.c
*/

#include "../../../../../include/game/rpg.h"

void set_change(LoadScene *load_scene, bool *out)
{
    load_scene->text = my_strdup("");
    load_scene->index_subtitle += 1;
    load_scene->sub = 0;
    *out = false;
}

void bool_change(bool *inverse, bool *out, bool first, bool second)
{
    *inverse = first;
    *out = second;
}

void fade_out_inverse(
    LoadScene *load_scene, bool *inverse, float time, bool *out)
{
    object_t *load_background = GET_OBJ(&load_scene->objects, LOAD_BACKGROUND);
    sfColor actual = sfColor_fromRGBA(255, 255, 255, 0);

    actual = sfSprite_getColor(load_background->sprite);
    if (!*inverse)
        return;
    if (object_get_scale(load_background).x < 1.04 && actual.a > 10 && *out) {
        actual.a -= (0.0001 * time);
        sfSprite_setColor(load_background->sprite, actual);
        if (actual.a <= 10)
            set_change(load_scene, out);
    }
    if (actual.a < 250 && !*out) {
        actual.a += (0.0001 * time);
        sfSprite_setColor(load_background->sprite, actual);
        if (actual.a >= 250)
            bool_change(inverse, out, false, true);
    }
}

void fade_out(
    LoadScene *load_scene, int path, object_t *load_background, float time)
{
    sfColor actual = sfColor_fromRGBA(255, 255, 255, 0);
    static bool out = true;
    static bool inverse = false;

    actual = sfSprite_getColor(load_background->sprite);
    if (object_get_scale(load_background).x > 1.21 && actual.a > 10 && out
        && !inverse) {
        actual.a -= (0.0001 * time);
        sfSprite_setColor(load_background->sprite, actual);
        if (actual.a <= 10)
            set_change(load_scene, &out);
    }
    if (object_get_scale(load_background).x > 1 && actual.a < 250 && !out
        && !inverse) {
        actual.a += (0.0001 * time);
        sfSprite_setColor(load_background->sprite, actual);
        if (actual.a >= 250)
            bool_change(&inverse, &out, true, true);
    }
    fade_out_inverse(load_scene, &inverse, time, &out);
}
