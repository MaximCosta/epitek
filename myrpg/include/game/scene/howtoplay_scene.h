/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef HOWPLAY_SCENE_H
    #define HOWPLAY_SCENE_H

    #include "../rpg.h"

typedef struct s_howplay_scene HowplayScene;

enum how_scene_objects {

    HBACKGROUND,
    DESCRIPTION,
    DESCRIPTION_BOARD,
    HBUTTON_QUIT,

};

struct s_howplay_scene {

    list_t *objects;

};

void on_howplay_render(void *scene);

void on_howplay_event(void *scene, sfEvent *event);

void *on_howplay_create(void);

#endif //HOWPLAY_SCENE_H
