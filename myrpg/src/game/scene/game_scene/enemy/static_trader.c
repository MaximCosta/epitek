/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** static_trader.c
*/

#include "../../../../../include/game/rpg.h"

void static_left(game *enmy, float speed, object_t *mob);
void static_right(game *enmy, float speed, object_t *mob);
void static_down(game *enmy, float speed, object_t *mob);
void static_up(game *enmy, float speed, object_t *mob);

void static_trader(game *scene, float speed, char *move)
{
    if (equal(move, "LEFT"))
        static_left(scene, speed, scene->trader->trader);
    if (equal(move, "RIGHT"))
        static_right(scene, speed, scene->trader->trader);
    if (equal(move, "DOWN"))
        static_down(scene, speed, scene->trader->trader);
    if (equal(move, "UP"))
        static_up(scene, speed, scene->trader->trader);
}
