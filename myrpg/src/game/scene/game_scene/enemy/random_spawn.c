/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** random_spawn.c
*/

#include "../../../../../include/game/rpg.h"

sfVector2i random_spawn(game *scene)
{
    object_t *map = object_get_from_uuid(&scene->objects, BACKGROUND_MAP);
    sfVector2i spawn = {0, 0};
    sfVector2i lower = {0, 0};
    sfVector2i upper = {0, 0};
    sfVector2f mapp = object_get_position(map);
    sfVector2f maps = object_get_size(map);

    srand(time(0));
    lower = (sfVector2i){mapp.x + 200, mapp.y + 200};
    upper = (sfVector2i){mapp.x + maps.x - 200, mapp.y + maps.y - 200};
    spawn.x = (rand() % (upper.x - lower.x + 1)) + lower.x;
    spawn.y = (rand() % (upper.y - lower.y + 1)) + lower.y;
    return spawn;
}
