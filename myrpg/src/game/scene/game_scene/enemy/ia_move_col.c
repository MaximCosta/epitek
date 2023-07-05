/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** all_move.c
*/

#include "../../../../../include/game/rpg.h"

bool get_collision(mob_t *actual, char *dir, mob_t *tmp_sh);
void left(object_t *mob, enemy_t *data, sfVector2f player_pos, bool crip);
void right(object_t *mob, enemy_t *data, sfVector2f player_pos, bool crip);
void down(object_t *mob, enemy_t *data, sfVector2f player_pos, bool crip);
void up(object_t *mob, enemy_t *data, sfVector2f player_pos, bool crip);

bool move_left_ia(mob_t *mob, mob_t *tmp_sh, sfVector2f player_pos)
{
    bool crip = false;

    if (get_collision(mob, "LEFT", tmp_sh)) {
        left(mob->mob, mob->data, player_pos, crip);
        return true;
    }
    crip = true;
    if (get_collision(mob, "UP", tmp_sh)) {
        up(mob->mob, mob->data, player_pos, crip);
        return true;
    } else if (get_collision(mob, "DOWN", tmp_sh)) {
        down(mob->mob, mob->data, player_pos, crip);
        return true;
    }
    return false;
}

bool move_right_ia(mob_t *mob, mob_t *tmp_sh, sfVector2f player_pos)
{
    bool crip = false;

    if (get_collision(mob, "RIGHT", tmp_sh)) {
        right(mob->mob, mob->data, player_pos, crip);
        return true;
    }
    crip = true;
    if (get_collision(mob, "UP", tmp_sh)) {
        up(mob->mob, mob->data, player_pos, crip);
        return true;
    } else if (get_collision(mob, "DOWN", tmp_sh)) {
        down(mob->mob, mob->data, player_pos, crip);
        return true;
    }
    return false;
}

bool move_up_ia(mob_t *mob, mob_t *tmp_sh, sfVector2f player_pos)
{
    bool crip = false;

    if (get_collision(mob, "UP", tmp_sh)) {
        up(mob->mob, mob->data, player_pos, crip);
        return true;
    }
    crip = true;
    if (get_collision(mob, "RIGHT", tmp_sh)) {
        right(mob->mob, mob->data, player_pos, crip);
        return true;
    } else if (get_collision(mob, "LEFT", tmp_sh)) {
        left(mob->mob, mob->data, player_pos, crip);
        return true;
    }
    return false;
}

bool move_down_ia(mob_t *mob, mob_t *tmp_sh, sfVector2f player_pos)
{
    bool crip = false;

    if (get_collision(mob, "DOWN", tmp_sh)) {
        down(mob->mob, mob->data, player_pos, crip);
        return true;
    }
    crip = true;
    if (get_collision(mob, "RIGHT", tmp_sh)) {
        right(mob->mob, mob->data, player_pos, crip);
        return true;
    } else if (get_collision(mob, "LEFT", tmp_sh)) {
        left(mob->mob, mob->data, player_pos, crip);
        return true;
    }
    return false;
}

bool all_move_ia(game *scene, mob_t *mob, mob_t *tmp_sh)
{
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);
    sfVector2f player_pos = object_get_position(player);
    if (object_get_scale(player).x > 0)
        player_pos.x -= 12;
    else
        player_pos.x -= 2;
    player_pos.y += 30;
    bool get_move = false;

    if (move_left_ia(mob, tmp_sh, player_pos))
        get_move = true;
    if (move_right_ia(mob, tmp_sh, player_pos))
        get_move = true;
    if (move_up_ia(mob, tmp_sh, player_pos))
        get_move = true;
    if (move_down_ia(mob, tmp_sh, player_pos))
        get_move = true;
    return get_move;
}
