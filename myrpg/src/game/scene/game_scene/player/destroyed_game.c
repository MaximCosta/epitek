/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** destroyed_game.c
*/

#include "../../../../../include/game/rpg.h"

void game_destroyed_prev(game *scene)
{
    mob_t *mobs = scene->mobs;

    for (; mobs != NULL; mobs = mobs->next) {
        scene_remove_object(&scene->objects, mobs->mob);
        scene_remove_object(&scene->objects, mobs->data->pv_text);
        scene->nb_enemy -= 1;
    }
    scene->mobs = NULL;
    OSP(OGFuuid_t(&scene->objects, BACKGROUND_MAP), (V2F){-540, -960});
    OSP(OGFuuid_t(&scene->objects, MAP_BACK), (V2F){-540, -960});
}

void game_destroyed_next(game *scene)
{
    game_destroyed_prev(scene);
    scene->stats->dolex = 0;
    scene->stats->active = false;
    scene->stats->is_lock = false;
    scene->quests->active = false;
    scene->quests->n_emeraude = 0;
    scene->quests->n_lapis = 0;
    scene->quests->n_redstone = 0;
    scene->quests->main_quest_active = false;
    scene->quests->n_quests = 0;
    scene->quests->is_lock = false;
    scene->player->damage = 25;
    scene->player->speed = 0.0001;
    scene->player->energy_damage = 200;
    scene->jet_power = 10;
    scene->player->lvl = 1;
    scene->player->inventory_st = false;
    scene->trader->active = false;
    scene->player->pause = false;
    scene->game_destroyed = true;
}
