/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef MENU_SCENE_H
    #define MENU_SCENE_H

    #include "../rpg.h"

typedef struct s_menu_scene MenuScene;

enum menu_scene_objects {
    BACKGROUND_MENU,
    CURSOR_M,
    PLAY_BUTTON,
    MULTIPLAYER_BUTTON,
    BACK_TO_MENU,
    BLACKSCREEN_M,
    TITLE,
    PEACEFUL,
    NORMAL,
    HARD,
    PERMANENT,
    FONDU,
    HOW_TO_PLAY,
    HTP_DRAW,
};

struct s_menu_scene {

    list_t *objects;
    bool mouse_press;
    bool slected_difficulty;
    int selected;
    int reverse;
    bool selected_htp;
    int wheel;
};

void on_menuscene_render(void *scene);

void on_menuscene_event(void *scene, sfEvent *event);

void *on_menuscene_create(void);

#endif //MENU_SCENE_H
