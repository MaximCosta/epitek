/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** player_ohter_movement.c
*/

#include "../../../../../include/game/rpg.h"

void move_right(game *scene, float time, object_t *map, float speed);
void move_left(game *scene, float time, object_t *map, float speed);
void move_up(game *scene, float time, object_t *map, float speed);
void move_down(game *scene, float time, object_t *map, float speed);

void reset_movement(game *scene, bool right, bool left, bool down)
{
    if (right)
        scene->player->RIGHT = true;
    if (left)
        scene->player->LEFT = true;
    if (down)
        scene->player->DOWN = true;
}

char player_down(char prev, game *scene, sfVector2i pos, object_t *map)
{
    if (scene->player->DOWN && scene->map[pos.y][pos.x] != '0' &&
    prev != 'u') {
        move_down(scene, ENGINE->delta_time, map, scene->player->speed);
        prev = 'd';
    }
    if (prev == 'u' && scene->player->DOWN &&
    scene->map[pos.y + 2][pos.x] != '0') {
        move_down(scene, ENGINE->delta_time, map, scene->player->speed);
        prev = 'u';
    } else if (prev == 'u' && scene->player->DOWN &&
    scene->map[pos.y][pos.x] != '0') {
        move_down(scene, ENGINE->delta_time, map, scene->player->speed);
        prev = 'd';
    }
    return prev;
}
