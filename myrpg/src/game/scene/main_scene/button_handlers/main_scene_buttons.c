/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../../../../include/game/rpg.h"

static const char *BUTTON_SETTINGS_S = "./assets/main/button_settings.png";
static const char *BUTTON_MUSIC_S = "./assets/main/button_music.png";
static const char *BUTTON_SOUND_S = "./assets/main/button_sound.png";
static const char *BUTTON_HOWPLAY_S = "./assets/main/button_howtoplay.png";

void on_hover_scale(object_t *object)
{
    sfVector2f vf = sfSprite_getScale(object->sprite);

    sfSprite_setScale(
        object->sprite, (sfVector2f){ vf.x + 0.15, vf.y + 0.15});
}

void on_unhover_scale(object_t *object)
{
    sfVector2f vf = sfSprite_getScale(object->sprite);

    sfSprite_setScale(
        object->sprite, (sfVector2f){ vf.x - 0.15, vf.y - 0.15});
}

static void onclick(object_t *object)
{
    sound_play(BUTTON_PRESS_SOUND);
    scene_change(HOWPLAY_SCENE);
}

object_t *load_how_play_button(main_scene_t *main_scene)
{
    object_t *play_button = object_create_from_image(
        BUTTON_HOWPLAY, (loc_t) {WIDTH / 2, HEIGHT / 1.2},
        BUTTON_HOWPLAY_S);

    object_set_origin(play_button, (sfVector2f) {248.5, 88});
    object_on_hover(play_button, &on_hover_scale);
    object_on_unhover(play_button, &on_unhover_scale);
    scene_add_object(&main_scene->objects, play_button);
    object_on_click(play_button, onclick);
    return play_button;
}
