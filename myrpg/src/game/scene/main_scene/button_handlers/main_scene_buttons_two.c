/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../../../../include/game/rpg.h"

static const char *BUTTON_PLAY_S = "./assets/main/button_play.png";
static const char *BUTTON_QUIT_S = "./assets/main/button_close.png";

static void on_button_quit_click(object_t *object)
{
    sound_play(BUTTON_PRESS_SOUND);
    scene_change(SHELL);
}

static void on_button_start_click(object_t *object)
{
    sound_play(BUTTON_PRESS_SOUND);
    music_play(GAME_MUSIC);
    music_set_repeated(music_get_from_uuid(GAME_MUSIC), true);
    music_pause(MAIN_MUSIC);
    scene_change(GAME_SCENE);
}

object_t *load_play_button(main_scene_t *main_scene)
{
    object_t *play_button = object_create_from_image(
        BUTTON_PLAY, (loc_t) {WIDTH / 2, HEIGHT / 2 + 80}, BUTTON_PLAY_S);

    object_set_origin(play_button, (sfVector2f) {165.5, 165.5});
    object_on_hover(play_button, &on_hover_scale);
    object_on_unhover(play_button, &on_unhover_scale);
    object_on_click(play_button, &on_button_start_click);
    scene_add_object(&main_scene->objects, play_button);
    return play_button;
}

object_t *load_quit_button(main_scene_t *main_scene)
{
    object_t *quit_button = object_create_from_image(
        BUTTON_QUIT, (loc_t) {WIDTH - 75, 75},
        BUTTON_QUIT_S);

    object_set_origin(quit_button, (sfVector2f) {52, 52});
    object_on_hover(quit_button, &on_hover_scale);
    object_on_unhover(quit_button, &on_unhover_scale);
    scene_add_object(&main_scene->objects, quit_button);
    object_on_click(quit_button, &on_button_quit_click);
    return quit_button;
}
