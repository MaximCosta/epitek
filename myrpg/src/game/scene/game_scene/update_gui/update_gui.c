/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** update_gui.c
*/

#include "../../../../../include/game/rpg.h"

void just_check(object_t *object);
void update_gui_profile(game *scene);

void update_lock(game *scene)
{
    if (object_on_hover(scene->quests->lock, &just_check) &&
        scene->player->PAUSE && scene->mouse_press) {
        if (scene->quests->is_lock == false)
            scene->quests->is_lock = true;
        else
            scene->quests->is_lock = false;
        scene->mouse_press = false;
    }
    if (object_on_hover(scene->stats->lock, &just_check) &&
        scene->player->PAUSE && scene->mouse_press) {
        if (scene->stats->is_lock == false)
            scene->stats->is_lock = true;
        else
            scene->stats->is_lock = false;
        scene->mouse_press = false;
    }
}

void update_this_gui(game *scene)
{
    update_lock(scene);
    if (scene->quests->is_lock)
        object_set_rect(scene->quests->lock, (sfIntRect){12, 0, 12, 16});
    else
        object_set_rect(scene->quests->lock, (sfIntRect){0, 0, 12, 16});
    if (scene->stats->is_lock)
        object_set_rect(scene->stats->lock, (sfIntRect){12, 0, 12, 16});
    else
        object_set_rect(scene->stats->lock, (sfIntRect){0, 0, 12, 16});
    update_gui_profile(scene);
}
