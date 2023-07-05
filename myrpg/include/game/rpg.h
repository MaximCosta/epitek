/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef MYDEFENDER_H
    #define MYDEFENDER_H
    #define ABS(x) (x < 0) ? -x : x
    #define OSP object_set_position
    #define OGP object_get_position
    #define OGFuuid_t object_get_from_uuid
    #define TSP textobject_set_position
    #define V2F sfVector2f
    #define TOGFUUID textobject_get_from_uuid
    #define TOSTR textobject_set_string
    #define MI my_itoa
    #define SAO scene_add_object
    #define OCFI object_create_from_image
    #define OSR object_set_rect
    #define OGR object_get_rect
    #define TOC textobject_create
    #define SAT scene_add_text
    #define TGS sfTexture_getSize

    #include <stdlib.h>
    #include "stdio.h"
    #include "time.h"
    #include "../engine/engine.h"
    #include "scene/main_scene.h"
    #include "scene/howtoplay_scene.h"
    #include "scene/game.h"
    #include "scene/game_scene.h"
    #include "scene/load_scene.h"
    #include "scene/menu_scene.h"
    #include "scene/switch_scene.h"
    #include "scene/spaceship_scene.h"
    #include "scene/shell.h"
    #include "scene/runner.h"

enum settings {

    MUSIC_SETTING,
    SOUND_SETTING

};

enum scenes {

    MAIN_SCENE,
    HOWPLAY_SCENE,
    GAME_SCENE,
    LOAD_SCENE,
    SWITCH_SCENE,
    SPACESHIP_SCENE,

};

enum musics {

    MAIN_MUSIC,
    GAME_MUSIC

};

enum sounds {

    BUTTON_PRESS_SOUND,
    TOWER_BUILD_SOUND

};

enum window_info {

    WIDTH = 1920,
    HEIGHT = 1080

};

void register_settings(void);
void register_musics(void);
bool scan(char *filepath, char **buffer);
void create_enemy(game *scene, char *type);

#endif //MYDEFENDER_H
