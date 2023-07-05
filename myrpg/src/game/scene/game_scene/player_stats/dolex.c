/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** dolex.c
*/

#include "../../../../../include/game/rpg.h"

#define TGFU textobject_get_from_uuid

void pay_shield(game *scene, object_t *shield)
{
    float calc = 0.00;
    textobject_t *pvmax = TGFU(&scene->objects, STATS_MAXPV_TXT);

    if (object_get_rect(shield).width >= 224) {
        scene->stats->LOAD_SHIELD = false;
        scene->mouse_press = false;
        object_set_rect(shield, (sfIntRect){0, 0, 0, 80});
        if (scene->stats->dolex > 0) {
            scene->stats->dolex--;
            calc = (float) ((15 * scene->player->pv_max) / 100);
            scene->player->pv_max += calc;
            textobject_set_string(pvmax, my_itoa(scene->player->pv_max, 0));
        }
    }
}

void dolex_shield(game *scene)
{
    static DeltaTime delta = {.time = 0.00, .saved = 0.00};
    object_t *shield = object_get_from_uuid(&scene->objects, LOAD_SHIELD);

    if (scene->stats->LOAD_SHIELD)
        object_set_rect(shield, (sfIntRect){0, 0,
        object_get_rect(shield).width + (ENGINE->delta_time * 0.00025), 80});
    else if (object_get_rect(shield).width > 0)
        object_set_rect(shield, (sfIntRect){0, 0,
        object_get_rect(shield).width - (ENGINE->delta_time * 0.00025), 80});
    if (object_get_rect(shield).width >= 224) {
        object_set_rect(shield, (sfIntRect){0, 0, 224, 80});
        if (elapsed_time_milliseconds(500, &delta.time, &delta.saved))
            pay_shield(scene, shield);
    }
}

void pay_damage(game *scene, object_t *damage)
{
    float calc = 0.00;
    textobject_t *st_damage = TGFU(&scene->objects, STATS_DAMAGE_TXT);

    if (object_get_rect(damage).width >= 224) {
        scene->stats->LOAD_DAMAGE = false;
        scene->mouse_press = false;
        object_set_rect(damage, (sfIntRect){0, 0, 0, 80});
        if (scene->stats->dolex > 0) {
            scene->stats->dolex--;
            calc = (float) ((10 * scene->player->damage) / 100);
            scene->player->damage += calc;
            textobject_set_string(st_damage,
            my_itoa(scene->player->damage, 0));
        }
    }
}

void pay_speed(game *scene, object_t *speed)
{
    textobject_t *l_speed = TGFU(&scene->objects, STATS_SPEED_TXT);
    char n1 = 0;
    char n2 = 0;
    char v = ',';
    char *text = my_strdup("");

    if (object_get_rect(speed).width >= 224) {
        scene->stats->LOAD_SHIELD = false;
        scene->mouse_press = false;
        object_set_rect(speed, (sfIntRect){0, 0, 0, 80});
        if (scene->stats->dolex > 0) {
            scene->stats->dolex--;
            scene->player->speed += 0.00002;
            n1 = my_itoa(scene->player->speed * 100000, 0)[0];
            n2 = my_itoa(scene->player->speed * 100000, 0)[1];
            text = my_strcat_char(my_strcat_char(text, n1), v);
            text = my_strcat_char(text, n2);
            textobject_set_string(l_speed, text);
        }
    }
}

void dolex_speed(game *scene)
{
    static DeltaTime delta = {.time = 0.00, .saved = 0.00};
    object_t *speed = object_get_from_uuid(&scene->objects, LOAD_SPEED);

    if (scene->stats->LOAD_SPEED)
        object_set_rect(speed, (sfIntRect){0, 0,
        object_get_rect(speed).width + (ENGINE->delta_time * 0.00025), 80});
    else if (object_get_rect(speed).width > 0)
        object_set_rect(speed, (sfIntRect){0, 0,
        object_get_rect(speed).width - (ENGINE->delta_time * 0.00025), 80});
    if (object_get_rect(speed).width >= 224) {
        object_set_rect(speed, (sfIntRect){0, 0, 224, 80});
        if (elapsed_time_milliseconds(500, &delta.time, &delta.saved))
            pay_speed(scene, speed);
    }
}
