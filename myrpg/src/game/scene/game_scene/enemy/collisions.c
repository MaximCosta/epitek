/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** collisions.c
*/

#include "../../../../../include/game/rpg.h"

bool inside(sfVector2f t_pos, sfVector2f t_size, mob_t *actual, sfVector2f ac)
{
    if (ac.x >= t_pos.x && ac.x <= t_pos.x + t_size.x && ac.y >= t_pos.y
        && ac.y <= t_pos.y + t_size.y)
        return true;
    return false;
}

bool get_collision(mob_t *actual, char *dir, mob_t *tmp_sh)
{
    mob_t *tmp = tmp_sh;
    sfVector2f mpos = (sfVector2f){0, 0};
    sfVector2f msize = (sfVector2f){0, 0};
    sfVector2f di = actual->data->dimension;
    sfVector2f ac = object_get_position(actual->mob);
    ac.x += di.x / 2;
    ac.y += di.y;
    di = (sfVector2f){30, 20};

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->id == actual->id)
            continue;
        msize = tmp->data->dimension;
        mpos = object_get_position(tmp->mob);
        if (equal(dir, "RIGHT")
            && inside(mpos, msize, actual, (sfVector2f){ac.x + di.x, ac.y}))
            return false;
        if (equal(dir, "LEFT")
            && inside(mpos, msize, actual, (sfVector2f){ac.x - di.x, ac.y}))
            return false;
        if (equal(dir, "DOWN")
            && inside(mpos, msize, actual, (sfVector2f){ac.x, ac.y + di.y}))
            return false;
        if (equal(dir, "UP")
            && inside(mpos, msize, actual, (sfVector2f){ac.x, ac.y - di.y}))
            return false;
    }
    return true;
}
