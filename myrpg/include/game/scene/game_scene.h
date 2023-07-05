/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef GAME_SCENE_H
    #define GAME_SCENE_H

    #include "../rpg.h"

typedef struct s_game_scene GameScene;

enum game_scene_guis {

    BUILDINGS_GUI,
    MENU,
    LOAD_MENU,
    SWITCH_SC,
    GAME,
    SPACESHIP,
    SHELL,
    RUNNER

};

enum game_scene_objects {

    GAME_BACKGROUND,
    GAME_TABLE_DOWN,
    FREEZE_SPELL_ICON,
    BURN_SPELL_ICON,
    CASTLE_ICON,
    CASTLE,
    EASTER,
    BUILDINGS_GUI_ICE,
    BUILDINGS_GUI_FIRE,
    BUILDINGS_GUI_WATER,


};

struct s_game_scene {

    list_t *objects;
    list_t *entities;
    game *game;

};

void load_buildings_gui(GameScene *game_scene);

void load_icons(GameScene *game_scene);

void on_gamescene_render(void *scene);

void on_gamescene_event(void *scene, sfEvent *event);

void *on_gamescene_create(void);

#endif //GAME_SCENE_H
