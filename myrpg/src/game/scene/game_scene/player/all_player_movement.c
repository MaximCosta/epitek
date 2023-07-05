/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** all_move.c
*/

#include "../../../../../include/game/rpg.h"

void move_right(game *scene, float time, object_t *map, float speed);
void move_left(game *scene, float time, object_t *map, float speed);
void move_up(game *scene, float time, object_t *map, float speed);
void move_down(game *scene, float time, object_t *map, float speed);
void reset_movement(game *scene, bool right, bool left, bool down);
char player_down(int prev, game *scene, sfVector2i pos, object_t *map);

void conditionnal_movement(game *scene, bool *right, bool *left, bool *down)
{
    if (scene->player->LEFT && scene->player->UP && scene->player->RIGHT) {
        scene->player->RIGHT = false;
        *right = true;
    }
    if (scene->player->LEFT && scene->player->DOWN && scene->player->RIGHT) {
        scene->player->LEFT = false;
        *left = true;
    }
    if (scene->player->RIGHT && scene->player->LEFT) {
        scene->player->LEFT = false;
        *left = true;
    }
    if (scene->player->UP && scene->player->DOWN) {
        scene->player->DOWN = false;
        *down = true;
    }
}

char player_left(char prev, game *scene, sfVector2i pos, object_t *map)
{
    if (scene->player->LEFT && scene->map[pos.y][pos.x] != '0' &&
    prev != 'r') {
        move_left(scene, ENGINE->delta_time, map, scene->player->speed);
        prev = 'l';
    }
    if (prev == 'r' && scene->player->LEFT &&
    scene->map[pos.y][pos.x - 2] != '0' && scene->map[pos.y][pos.x] == '0') {
        move_left(scene, ENGINE->delta_time, map, scene->player->speed);
        prev = 'r';
    } else if (prev == 'r' && scene->player->LEFT &&
    scene->map[pos.y][pos.x] != '0') {
        move_left(scene, ENGINE->delta_time, map, scene->player->speed);
        prev = 'l';
    }
    return prev;
}

char player_right(char prev, game *scene, sfVector2i pos, object_t *map)
{
    if (scene->player->RIGHT && scene->map[pos.y][pos.x] != '0' &&
    prev != 'l') {
        move_right(scene, ENGINE->delta_time, map, scene->player->speed);
        prev = 'r';
    }
    if (prev == 'l' && scene->player->RIGHT &&
    scene->map[pos.y][pos.x + 2] != '0') {
        move_right(scene, ENGINE->delta_time, map, scene->player->speed);
        prev = 'l';
    } else if (prev == 'l' && scene->player->RIGHT &&
    scene->map[pos.y][pos.x] != '0') {
        move_right(scene, ENGINE->delta_time, map, scene->player->speed);
        prev = 'r';
    }
    return prev;
}

char player_up(char prev, game *scene, sfVector2i pos, object_t *map)
{
    if (scene->player->UP && scene->map[pos.y][pos.x] != '0' &&
    prev != 'd') {
        move_up(scene, ENGINE->delta_time, map, scene->player->speed);
        prev = 'u';
    }
    if (prev == 'd' && scene->player->UP &&
    scene->map[pos.y - 2][pos.x] != '0') {
        move_up(scene, ENGINE->delta_time, map, scene->player->speed);
        prev = 'd';
    } else if (prev == 'd' && scene->player->UP &&
    scene->map[pos.y][pos.x] != '0') {
        move_up(scene, ENGINE->delta_time, map, scene->player->speed);
        prev = 'u';
    }
    return prev;
}

void all_player_movement(game *scene, sfVector2f pos, object_t *map, float speed)
{
    object_t *player = OGFuuid_t(&scene->objects, PLAYER);
    sfVector2i new_pos = {0};
    static char prev = '\0';
    bool right = false;
    bool left = false;
    bool down = false;
    conditionnal_movement(scene, &right, &left, &down);
    pos.y -= 0.6;
    if (object_get_scale(player).x > 0)
        pos.x -= 0.6;
    else
        pos.x += 0.5;
    new_pos = (sfVector2i){(int)pos.x, (int)pos.y};
    prev = player_left(prev, scene, new_pos, map);
    prev = player_right(prev, scene, new_pos, map);
    prev = player_up(prev, scene, new_pos, map);
    prev = player_down(prev, scene, new_pos, map);
    reset_movement(scene, right, left, down);
}
