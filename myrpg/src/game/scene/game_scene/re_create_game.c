/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** re_create_game.c
*/

#include "../../../../include/game/rpg.h"

static const char *MONEY_S = "./assets/GameScene/inventory/money.png";
static const char *MONEY_FLITEM_S = "./assets/GameScene/inventory/"
                                    "money_item.png";
static const char *ITEM_RESURRECTION_S = "./assets/GameScene/items/"
"resurrection.png";
static const char *FLITEM_ITEM_RESURRECTION_S = "./assets/GameScene/inventory/"
"resurrection.png";

void add_item(game *scene, char *filepath, int id, char const **image);

void re_create_one(game *scene)
{
    scene->game_destroyed = false;
    scene->mouse_press = false;
    scene->nb_enemy = 0;
    scene->player->DOWN = false;
    scene->player->UP = false;
    scene->player->LEFT = false;
    scene->player->RIGHT = false;
    scene->player->ATTACK = false;
    scene->player->is_profile_gui_opened = false;
    scene->player->INVENTORY_O = false;
    scene->player->JETPACK = false;
    scene->player->ENERGY_ATTACK = false;
    scene->player->INTERACTION = false;
    scene->player->DASH = false;
    scene->player->HIT = false;
    scene->player->PAUSE = false;
    scene->mobs = NULL;
}

void re_create_two(game *scene)
{
    char const *tab[2] = {MONEY_S, MONEY_FLITEM_S};

    scene->player->lvl = 1;
    scene->jet_power = 10;
    scene->player->pv_max = 100;
    scene->player->damage = 25;
    scene->player->energy_damage = 200;
    scene->player->speed = 0.0001;

    add_item(scene, "money.txt", MONEY, tab);
    scene->player->money = 1000;
    scene->energy_power = 50;
    scene->save_hover = -1;
    scene->toolbar->pv = 100;
    scene->player->xp = 0;
    scene->player->xp_max = 500;
}

void re_create_three(game *scene)
{
    char *map = NULL;

    scan("assets/GameScene/map/map.txt", &map);
    scene->flitem = NULL;
    scene->stats->active = false;
    scene->stats->LOAD_SHIELD = false;
    scene->stats->LOAD_DAMAGE = false;
    scene->stats->LOAD_SPEED = false;
    scene->stats->dolex = 0;
    scene->quests->active = false;
    scene->quests->n_quests = 0;
    scene->quests->is_lock = false;
    scene->stats->is_lock = false;
    scene->quests->main_quest_active = false;
    scene->quests->on_click = false;
    scene->quests->n_lapis = 0;
    scene->quests->n_emeraude = 0;
}

void re_create_game(game *scene)
{
    char const *tab[2] = {ITEM_RESURRECTION_S, FLITEM_ITEM_RESURRECTION_S};

    re_create_one(scene);
    re_create_two(scene);
    re_create_three(scene);
    scene->quests->n_redstone = 0;
    textobject_set_string(TOGFUUID(&scene->objects,
    PLAYER_LVL_TEXT), "Level : 1");
    textobject_set_string(TOGFUUID(&scene->objects, STATS_MAXPV_TXT), "100");
    textobject_set_string(TOGFUUID(&scene->objects, STATS_DAMAGE_TXT), "25");
    textobject_set_string(TOGFUUID(&scene->objects, STATS_SPEED_TXT), "1");
    scene->difficulty = transaction(0);
    for (; scene->difficulty > 0; scene->difficulty -= 1)
        add_item(scene, "resurrection.txt", ITEM_RESURRECTION, tab);
}
