/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** player.c
*/

#include "../../../../../include/game/rpg.h"

void run_animated(game *scene, object_t *player);
void idle_animated(game *scene, object_t *player);
void new_cam_move(game *scene, sfVector2f p_pos);
void map_calc(game *scene, sfVector2f *p_pos, object_t *map, object_t *player);
void player_dash(game *scene, object_t *map, float speed);
void jetpack_animated(game *scene, object_t *player);
void static_enemy(game *scene, float speed, char *move);
void all_player_movement(game *scene, sfVector2f pos, object_t *map,
float speed);
void hit_animated(game *scene, object_t *player);
void player_death(game *scene);

void move_right(game *scene, float time, object_t *map, float speed)
{
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);
    object_t *b_map = object_get_from_uuid(&scene->objects, MAP_BACK);
    sfVector2f b_pos = OGP(b_map);

    if (OGP(map).x + 1280 > 0 && OGP(player).x >= 960) {
        OSP(map, (sfVector2f){OGP(map).x - (speed * time), OGP(map).y});
        OSP(b_map, (sfVector2f){b_pos.x - (speed * time), b_pos.y});
        static_enemy(scene, speed, "RIGHT");
    } else if (OGP(player).x < 1920) {
        OSP(player, (sfVector2f){OGP(player).x + (speed * time),
        OGP(player).y});
    }
    if (object_get_scale(player).x < 0) {
        object_set_scale(player, (sfVector2f){2, 2});
        OSP(player, (sfVector2f){OGP(player).x + 32, OGP(player).y});
    }
}

void move_left(game *scene, float time, object_t *map, float speed)
{
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);
    object_t *b_map = object_get_from_uuid(&scene->objects, MAP_BACK);
    sfVector2f b_pos = OGP(b_map);

    if (OGP(map).x < 0 && OGP(player).x <= 960) {
        OSP(map, (sfVector2f){OGP(map).x + (speed * time), OGP(map).y});
        OSP(b_map, (sfVector2f){b_pos.x + (speed * time), b_pos.y});
        static_enemy(scene, speed, "LEFT");
    } else if (OGP(player).x > 0) {
        OSP(player, (sfVector2f){OGP(player).x - (speed * time),
        OGP(player).y});
    }
    if (object_get_scale(player).x > 0) {
        object_set_scale(player, (sfVector2f){-2, 2});
        OSP(player, (sfVector2f){OGP(player).x - 32, OGP(player).y});
    }
}

void move_up(game *scene, float time, object_t *map, float speed)
{
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);
    object_t *b_map = object_get_from_uuid(&scene->objects, MAP_BACK);
    sfVector2f b_pos = OGP(b_map);

    if (scene->player->JETPACK)
        speed *= 2;
    if (OGP(map).y < 0 && OGP(player).y <= 540) {
        OSP(map, (sfVector2f){OGP(map).x, OGP(map).y + (speed * time)});
        OSP(b_map, (sfVector2f){b_pos.x, b_pos.y + (speed * time)});
        static_enemy(scene, speed, "UP");
    } else if (OGP(player).y > -5)
        OSP(player, (sfVector2f){OGP(player).x,
        OGP(player).y - (speed * time)});
}

void move_down(game *scene, float time, object_t *map, float speed)
{
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);
    object_t *b_map = object_get_from_uuid(&scene->objects, MAP_BACK);
    sfVector2f b_pos = OGP(b_map);

    if (scene->player->JETPACK)
        speed *= 2;
    if (OGP(map).y + 2040 > 0 && OGP(player).y >= 540) {
        OSP(map, (sfVector2f){OGP(map).x, OGP(map).y - (speed * time)});
        OSP(b_map, (sfVector2f){b_pos.x, b_pos.y - (speed * time)});
        static_enemy(scene, speed, "DOWN");
    } else if (OGP(player).y < 1080)
        OSP(player, (sfVector2f){OGP(player).x,
        OGP(player).y + (speed * time)});
}

void player_movement(game *scene)
{
    object_t *map = object_get_from_uuid(&scene->objects, BACKGROUND_MAP);
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);
    sfVector2f p_pos = {0, 0};

    if (scene->toolbar->pv <= 0)
        return player_death(scene);
    map_calc(scene, &p_pos, map, player);
    player_dash(scene, map, scene->player->speed);
    jetpack_animated(scene, player);
    hit_animated(scene, player);
    if (scene->player->ATTACK || scene->player->PAUSE ||
    scene->player->DASH || scene->player->ENERGY_ATTACK)
        return;
    all_player_movement(scene, p_pos, map,
    scene->player->speed);
    run_animated(scene, player);
    if (!scene->player->RIGHT && !scene->player->LEFT &&
    !scene->player->DOWN && !scene->player->UP)
        idle_animated(scene, player);
    sfRenderWindow_setView(ENGINE->window, scene->view);
}
