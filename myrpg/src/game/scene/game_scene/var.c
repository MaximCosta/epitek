/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** var.c
*/

#include "../../../../include/game/rpg.h"

static const char *MONEY_S = "./assets/GameScene/inventory/money.png";
static const char *MONEY_FLITEM_S = "./assets/GameScene/inventory/"
                                    "money_item.png";
static const char *LOCK_S = "./assets/GameScene/GUI/lock.png";
static const char *COLOR_PALETTE =
    "./assets/GameScene/GUI/profile/profile_palette.png";

void add_item(game *scene, char *filepath, int id, char const **image);
void var_other(game *scene);

void add_level_text(game *scene)
{
    char *lvl = "Level : ";
    textobject_t *level = NULL;

    lvl = my_strcat(lvl, my_itoa(scene->player->lvl, 0));
    scene_add_text(&scene->objects, textobject_create(
        PLAYER_LVL_TEXT, (loc_t){100, 60}, lvl));
    level = textobject_get_from_uuid(&scene->objects, PLAYER_LVL_TEXT);
    textobject_set_size(level, 15);
    object_set_render_priority(level->object, 200);
}

void init_stats_and_quests(game *scene)
{
    scene->stats = malloc(sizeof(stats_t));
    scene->quests = malloc(sizeof(quests_t));
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
    scene->stats->lock = object_create_from_image(
        LOCK, (loc_t){240, 101}, LOCK_S);
    scene->quests->lock = object_create_from_image(
        LOCK, (loc_t){240, 131}, LOCK_S);
    scene_add_object(&scene->objects, scene->quests->lock);
    scene_add_object(&scene->objects, scene->stats->lock);
    object_set_render_priority(scene->quests->lock, 130);
    object_set_render_priority(scene->stats->lock, 112);
}

void init_var_2(game *scene)
{
    char *map = NULL;
    char const *tab[2] = {MONEY_S, MONEY_FLITEM_S};

    add_item(scene, "money.txt", MONEY, tab);
    scene->player->money = 1000;
    scene->energy_power = 50;
    scene->save_hover = -1;
    scene->toolbar->pv = 100;
    scene->player->xp = 0;
    scene->player->xp_max = 500;
    scan("assets/GameScene/map/map.txt", &map);
    scene->flitem = NULL;
    scene->map = to_2d_array(map);
    scene->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    add_level_text(scene);
    sfView_setCenter(scene->view, (sfVector2f){960, 540});
    sfRenderWindow_setView(ENGINE->window, scene->view);
}

void init_player(game *scene)
{
    scene->player->lvl = 1;
    scene->jet_power = 10;
    scene->player->pv_max = 100;
    scene->player->damage = 25;
    scene->player->energy_damage = 200;
    scene->player->speed = 0.0001;
}

void init_var(game *scene)
{
    scene->player = malloc(sizeof(player_t));
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
    scene->color_palette = sfImage_createFromFile(COLOR_PALETTE);
    init_player(scene);
    init_var_2(scene);
    init_stats_and_quests(scene);
    var_other(scene);
}
