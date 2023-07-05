/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** update_stats.c
*/

#include "../../../../../include/game/rpg.h"

void info_rect_speed(game *scene, object_t *stats, object_t *speed);
void info_rect_damage(game *scene, object_t *stats, object_t *damage);
void rect_load_skills(game *scene);
void update_dolex_text(game *scene);
void dolex_shield(game *scene);
void pay_damage(game *scene, object_t *damage);
void dolex_speed(game *scene);

bool mouse_inside(object_t *object)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(ENGINE->window);
    sfVector2f obj_pos = object_get_position(object);
    sfIntRect rect = object_get_rect(object);

    if (rect.left > 0) {
        rect.height /= 2;
        obj_pos.y += rect.height;
    }
    obj_pos.y += rect.top;
    if ((mouse_pos.x >= obj_pos.x && mouse_pos.x <=
    obj_pos.x + rect.width) &&
    (mouse_pos.y >= obj_pos.y && mouse_pos.y <=
    obj_pos.y + rect.height))
        return true;
    return false;
}

void info_rect_2(game *scene, object_t *stats)
{
    object_t *dolex = object_get_from_uuid(&scene->objects, INFO_DOLEX);

    if (mouse_inside(dolex) &&
    object_get_rect(stats).height >= 300)
        object_set_rect(dolex, (sfIntRect){224, 0, 224, 124});
    else
        object_set_rect(dolex, (sfIntRect){0, 62, 224, 62});
}

void info_rect(game *scene, object_t *shield, object_t *damage, object_t *speed)
{
    object_t *stats = object_get_from_uuid(&scene->objects, PLAYER_STATS);

    if (mouse_inside(shield) &&
    object_get_rect(stats).height >= 300 &&
    scene->player->PAUSE) {
        object_set_rect(shield, (sfIntRect){224, 0, 224, 165});
        if (scene->mouse_press)
            scene->stats->LOAD_SHIELD = true;
        else
            scene->stats->LOAD_SHIELD = false;
    } else {
        object_set_rect(shield, (sfIntRect){0, 82.5, 224, 82.5});
        scene->stats->LOAD_SHIELD = false;
    }
    info_rect_damage(scene, stats, damage);
    info_rect_speed(scene, stats, speed);
    info_rect_2(scene, stats);
    rect_load_skills(scene);
}

void update_load_skills(game *scene)
{
    static DeltaTime delta = {.time = 0.00, .saved = 0.00};
    object_t *damage = object_get_from_uuid(&scene->objects, LOAD_DAMAGE);

    dolex_shield(scene);
    dolex_speed(scene);
    if (scene->stats->LOAD_DAMAGE)
        object_set_rect(damage, (sfIntRect){0, 0,
        object_get_rect(damage).width + (ENGINE->delta_time * 0.00025), 80});
    else if (object_get_rect(damage).width > 0)
        object_set_rect(damage, (sfIntRect){0, 0,
        object_get_rect(damage).width - (ENGINE->delta_time * 0.00025), 80});
    if (object_get_rect(damage).width >= 224) {
        object_set_rect(damage, (sfIntRect){0, 0, 224, 80});
        if (elapsed_time_milliseconds(500, &delta.time, &delta.saved))
            pay_damage(scene, damage);
    }
}

void update_stats(game *scene, textobject_t *pvmax, textobject_t *damage_txt,
textobject_t *speed_txt)
{
    object_t *shield = object_get_from_uuid(&scene->objects, INFO_SHIELD);
    object_t *damage = object_get_from_uuid(&scene->objects, INFO_DAMAGE);
    object_t *speed = object_get_from_uuid(&scene->objects, INFO_SPEED);

    if (scene->menu->active)
        return;
    info_rect(scene, shield, damage, speed);
    update_load_skills(scene);
    update_dolex_text(scene);
}
