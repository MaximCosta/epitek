/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../../../../include/game/rpg.h"

static const char *BUTTON_MUSIC_S = "./assets/main/button_sound.png";
static const char *BUTTON_SOUND_S = "./assets/main/button_music.png";
static const char *BUTTON_MUSIC_OFF_S = "./assets/main/button_sound_off.png";
static const char *BUTTON_SOUND_OFF_S = "./assets/main/button_music_off.png";

static void onclick_music(object_t *object)
{
    bool *music_setting = setting_get_value(MUSIC_SETTING);

    if (*music_setting) {
        sfTexture_destroy((sfTexture *) sfSprite_getTexture(object->sprite));
        sfSprite_setTexture(object->sprite,
            sfTexture_createFromFile(BUTTON_MUSIC_OFF_S, NULL), false);
        sfMusic_pause(music_get_from_uuid(MAIN_MUSIC)->sf_music);
    } else {
        sfTexture_destroy((sfTexture *) sfSprite_getTexture(object->sprite));
        sfSprite_setTexture(object->sprite,
            sfTexture_createFromFile(BUTTON_MUSIC_S, NULL), false);
        sfMusic_play(music_get_from_uuid(MAIN_MUSIC)->sf_music);
    }
    *music_setting ^= 1;
    sound_play(BUTTON_PRESS_SOUND);
}

static void onclick_sound(object_t *object)
{
    bool *sound_setting = (bool *)setting_get_value(SOUND_SETTING);

    if (*sound_setting) {
        sfTexture_destroy((sfTexture *) sfSprite_getTexture(object->sprite));
        sfSprite_setTexture(object->sprite,
            sfTexture_createFromFile(BUTTON_SOUND_OFF_S, NULL), false);
        *sound_setting = false;
    } else {
        sfTexture_destroy((sfTexture *) sfSprite_getTexture(object->sprite));
        sfSprite_setTexture(object->sprite,
            sfTexture_createFromFile(BUTTON_SOUND_S, NULL), false);
        *sound_setting = true;
    }
    sound_play(BUTTON_PRESS_SOUND);
}

object_t *load_sound_button(main_scene_t *main_scene)
{
    object_t *sound_button = object_create_from_image(
        BUTTON_SOUND, (loc_t) {350, 130}, BUTTON_SOUND_S);

    scene_add_object(&main_scene->objects, sound_button);
    object_set_origin(sound_button, (sfVector2f) {88, 88});
    object_on_unhover(sound_button, &on_unhover_scale);
    object_on_hover(sound_button, &on_hover_scale);
    object_on_click(sound_button, &onclick_sound);
    return sound_button;
}

object_t *load_music_button(main_scene_t *main_scene)
{
    object_t *music_button = object_create_from_image(
        BUTTON_MUSIC, (loc_t) {150, 130}, BUTTON_MUSIC_S);

    object_set_origin(music_button, (sfVector2f) {88, 88});
    object_on_hover(music_button, &on_hover_scale);
    object_on_unhover(music_button, &on_unhover_scale);
    scene_add_object(&main_scene->objects, music_button);
    object_on_click(music_button, &onclick_music);
    return music_button;
}
