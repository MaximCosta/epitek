/*
** EPITECH PROJECT, 2021
** template
** File description:
** template
*/

#ifndef GAME_H
#define GAME_H
#define EXTERNC extern "C"

#include "../engine/Engine.hpp"
#include "scene/MainScene.hpp"
#include "scene/LoadingScene.hpp"
#include "scene/GameScene.hpp"
#include "scene/HowToPlayScene.hpp"

extern "C" {
    #include "../../../corewar/include/corewar.h"
    void start_graphic_mode(corewar_t *corewar);
}


#endif // GAME_H