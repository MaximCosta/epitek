/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** update_quests.c
*/

#include "../../../../../include/game/rpg.h"

void just_check(object_t *object);
void accpet_quests(game *scene);
void update_main_quest(game *scene);
void check_crystal(game *scene);

void quests_active(game *scene, object_t *quests)
{
    if (object_on_hover(quests, &just_check) && scene->player->PAUSE &&
    !object_on_hover(scene->quests->lock, &just_check)) {
        object_set_rect(quests, (sfIntRect){771, 0, 257, 20});
        if (scene->mouse_press) {
            scene->mouse_press = false;
            scene->quests->active = false;
            scene->quests->is_lock = false;
        }
    } else if (scene->player->PAUSE) {
        object_set_rect(quests, (sfIntRect){514, 0, 257, 20});
    }
}

void quests_deactive(game *scene, object_t *quests)
{
    if (object_on_hover(quests, &just_check) && scene->player->PAUSE
    && !object_on_hover(scene->quests->lock, &just_check)) {
        object_set_rect(quests, (sfIntRect){257, 0, 257, 20});
        if (scene->mouse_press) {
            scene->mouse_press = false;
            scene->quests->active = true;
        }
    } else if (scene->player->PAUSE) {
        object_set_rect(quests, (sfIntRect){0, 0, 257, 20});
    }
}

void update_position(game *scene, object_t *quests, object_t *player_quests)
{
    sfVector2f pos = object_get_position(quests);
    sfVector2f q_pos = object_get_position(player_quests);
    sfVector2f l_pos = object_get_position(scene->quests->lock);

    if (!scene->stats->active && pos.y > 135) {
        object_set_position(quests, (sfVector2f){pos.x, pos.y - (
            0.001 * ENGINE->delta_time)});
        object_set_position(scene->quests->lock, (sfVector2f){l_pos.x, l_pos.y
            - (0.001 * ENGINE->delta_time)});
    } else if (scene->stats->active && pos.y < 520) {
        object_set_position(quests, (sfVector2f){pos.x, pos.y + (
            0.001 * ENGINE->delta_time)});
        object_set_position(scene->quests->lock, (sfVector2f){l_pos.x, l_pos.y
            + (0.001 * ENGINE->delta_time)});
    }
    if (!scene->stats->active && q_pos.y > 152)
        object_set_position(player_quests, (sfVector2f){pos.x, q_pos.y - (
            0.001 * ENGINE->delta_time)});
    else if (scene->stats->active && q_pos.y < 550)
        object_set_position(player_quests, (sfVector2f){pos.x, q_pos.y + (
            0.001 * ENGINE->delta_time)});
}

void update_player_quests(game *scene, object_t *player_quests)
{
    sfIntRect rect = object_get_rect(player_quests);
    object_t *btn = object_get_from_uuid(&scene->objects, QUESTS_BTN);

    if (scene->quests->n_quests == 0)
        rect.left = 257;
    else
        rect.left = 0;
    if (!scene->player->PAUSE && !scene->quests->is_lock) {
        object_set_rect(btn, (sfIntRect){0, 0, 257, 20});
        scene->quests->active = false;
    }
    if (scene->quests->active && rect.height < 400)
        object_set_rect(player_quests, (sfIntRect){rect.left, 0, 257,
        rect.height + (0.001 * ENGINE->delta_time)});
    else if (rect.height >= 2 && !scene->quests->active)
        object_set_rect(player_quests, (sfIntRect){rect.left, 0, 257,
        rect.height - (0.001 * ENGINE->delta_time)});
    if (rect.height <= 2 && !scene->quests->active)
        object_set_rect(player_quests, (sfIntRect){rect.left, 0, 257, 0});
}

void update_quests(game *scene)
{
    object_t *quests = object_get_from_uuid(&scene->objects, QUESTS_BTN);
    object_t *player_quests = object_get_from_uuid(&scene->objects,
        PLAYER_QUESTS);

    if (scene->menu->active)
        return;
    accpet_quests(scene);
    check_crystal(scene);
    update_main_quest(scene);
    update_player_quests(scene, player_quests);
    update_position(scene, quests, player_quests);
    if (scene->quests->active)
        quests_active(scene, quests);
    else
        quests_deactive(scene, quests);
}
