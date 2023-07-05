/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef SWICTH_SCENE_H
    #define SWICTH_SCENE_H

    #include "../rpg.h"

typedef struct s_switch_scene SwitchScene;

enum switch_scene_objects {

    SWITCH_BACKGROUND,
    SWITCH_CURSOR,
    TIPS

};

struct s_switch_scene {

    list_t *objects;
    bool mouse_press;
    char **tips;

};


void on_switch_scene_render(void *scene);

void on_switch_scene_event(void *scene, sfEvent *event);

void *on_switch_scene_create(void);

#endif //SWICTH_SCENE_H
