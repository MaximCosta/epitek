/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef MAIN_SCENE_H
    #define MAIN_SCENE_H

    #include "../rpg.h"

typedef struct s_main_scene main_scene_t;

enum main_scene_objects {

    BACKGROUND,
    ROPE_ONE,
    ROPE_TWO,
    LOGO,
    BUTTON_SETTINGS,
    BUTTON_SOUND,
    BUTTON_MUSIC,
    BUTTON_PLAY,
    BUTTON_HOWPLAY,
    BUTTON_QUIT,
    COIN_IMAGE,
    COIN_TEXT,
    GAME_LOGO,
    CURSOR,
    PARTICLES,
    BLACKSCREEN

};

struct s_main_scene {

    list_t *objects;
    sfColor opacity;
    bool transition;

};

object_t *load_sound_button(main_scene_t *main_scene);

object_t *load_music_button(main_scene_t *main_scene);

object_t *load_play_button(main_scene_t *main_scene);

object_t *load_how_play_button(main_scene_t *main_scene);

object_t *load_quit_button(main_scene_t *main_scene);

void on_mainscene_render(void *scene);

void on_mainscene_event(void *scene, sfEvent *event);

void *on_mainscene_create(void);

void on_hover_scale(object_t *object);

void on_unhover_scale(object_t *object);


#endif //MAIN_SCENE_H
