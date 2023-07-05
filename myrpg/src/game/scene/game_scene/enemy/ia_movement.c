/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** ia_movement.c
*/

#include "../../../../../include/game/rpg.h"

bool get_collision(mob_t *actual, char *dir, mob_t *tmp_sh);
bool all_move_ia(game *scene, mob_t *mob, mob_t *tmp_sh);

void left(object_t *mob, enemy_t *data, sfVector2f player_pos, bool crip)
{
    sfVector2f mob_pos = object_get_position(mob);
    sfVector2f point = mob_pos;
    float val = (float) data->speed / 30000;
    float speed = (float) val * ENGINE->delta_time;

    if (equal(data->type, "PHANTOM"))
        point.y += 40;
    if (point.x > player_pos.x || crip)
        object_set_position(mob, (sfVector2f){mob_pos.x - speed, mob_pos.y});
    if (point.x > player_pos.x + 30 && object_get_scale(mob).x == 1) {
        object_set_scale(mob, (sfVector2f){-1, 1});
        object_set_position(
            mob, (sfVector2f){mob_pos.x - data->dimension.x / 2, mob_pos.y});
    }
}

void right(object_t *mob, enemy_t *data, sfVector2f player_pos, bool crip)
{
    sfVector2f mob_pos = object_get_position(mob);
    sfVector2f point = mob_pos;
    float val = (float) data->speed / 30000;
    float speed = (float) val * ENGINE->delta_time;

    if (equal(data->type, "PHANTOM"))
        point.y += 40;
    if (point.x < player_pos.x || crip)
        object_set_position(mob, (sfVector2f){mob_pos.x + speed, mob_pos.y});
    if (point.x < player_pos.x - 30 && object_get_scale(mob).x == -1) {
        object_set_scale(mob, (sfVector2f){1, 1});
        object_set_position(
            mob, (sfVector2f){mob_pos.x + data->dimension.x / 2, mob_pos.y});
    }
}

void down(object_t *mob, enemy_t *data, sfVector2f player_pos, bool crip)
{
    sfVector2f mob_pos = object_get_position(mob);
    sfVector2f point = mob_pos;
    float val = (float) data->speed / 30000;
    float speed = (float) val * ENGINE->delta_time;

    if (equal(data->type, "PHANTOM"))
        point.y += 40;
    if (point.y < player_pos.y || crip)
        object_set_position(mob, (sfVector2f){mob_pos.x, mob_pos.y + speed});
}

void up(object_t *mob, enemy_t *data, sfVector2f player_pos, bool crip)
{
    sfVector2f mob_pos = object_get_position(mob);
    sfVector2f point = mob_pos;
    float val = (float) data->speed / 30000;
    float speed = (float) val * ENGINE->delta_time;

    if (equal(data->type, "PHANTOM"))
        point.y += 40;
    if (point.y > player_pos.y || crip)
        object_set_position(mob, (sfVector2f){mob_pos.x, mob_pos.y - speed});
}

void ia_movement(game *scene, mob_t *mob, mob_t *tmp_sh)
{
    if (!all_move_ia(scene, mob, tmp_sh) && !equal(mob->data->state, "HIT"))
        mob->data->state = my_strdup("IDLE");
}
