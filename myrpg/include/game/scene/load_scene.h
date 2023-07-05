/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef LOAD_SCENE_H
    #define LOAD_SCENE_H

    #include "../rpg.h"

typedef struct s_load_scene LoadScene;

enum load_scene_musics {

    VOICE_OFF

};

enum load_scene_objects {

    LOAD_BACKGROUND,
    LOAD_BLACKSCREEN,
    SKIP,
    CURSOR_LOAD,
    SUBTITLE

};

struct s_load_scene {

    list_t *objects;
    bool mouse_press;
    char **subtitle;
    char *text;
    int index_subtitle;
    int sub;
    DeltaTime delta_time;

};


void on_loadscene_render(void *scene);

void on_loadscene_event(void *scene, sfEvent *event);

void *on_loadscene_create(void);

#endif //LOAD_SCENE_H
