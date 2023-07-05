/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** add_gui.c
*/

#include "../../../../../include/game/rpg.h"

static const char *PV_BACK_S = "./assets/GameScene/GUI/pv_back.png";
static const char *PV_S = "./assets/GameScene/GUI/pv.png";
static const char *TOOLBAR_S = "./assets/GameScene/GUI/toolbar.png";
static const char *ACTION_S = "./assets/GameScene/GUI/action.png";
static const char *KEY_ACTION_S = "./assets/GameScene/GUI/key_action.png";
static const char *TOOL_XP_BACK_S = "./assets/GameScene/GUI/toolxp1.png";
static const char *TOOL_XP_FRONT_S = "./assets/GameScene/GUI/toolxp2.png";
static const char *PLAYER_ICON_S = "./assets/GameScene/GUI/profile/profile.png";
static const char *MOUSE_STATE_S = "./assets/GameScene/GUI/mouse_state.png";
static const char *PLAYER_STATS_BTN_S = "./assets/GameScene/GUI/"
"player_stats_btn.png";
static const char *PLAYER_STATS_S = "./assets/GameScene/GUI/player_stats.png";
static const char *INFO_SHIELD_S = "./assets/GameScene/GUI/info_shield.png";
static const char *INFO_DAMAGE_S = "./assets/GameScene/GUI/info_damage.png";
static const char *INFO_SPEED_S = "./assets/GameScene/GUI/info_speed.png";
static const char *INFO_DOLEX_S = "./assets/GameScene/GUI/info_dolex.png";

void toolbar_action_x(game *scene, int i, bool live, float speed);
void update_toolbar(game *scene);
void update_gui(game *scene);
void stats(game *scene);
void add_toolxp(game *scene);
void add_quests(game *scene);
void add_settings_menu(game *scene);

void add_toolbar(game *scene)
{
    scene->toolbar = malloc(sizeof(toolbar_t));
    scene->toolbar->actions = malloc(sizeof(object_t *) * 4);
    int x = 610;

    for (int i = 0; i != 4; i++) {
        scene->toolbar->actions[i] = object_create_from_image(
            ACTION, (loc_t){x, 1050}, ACTION_S);
        scene_add_object(&scene->objects, scene->toolbar->actions[i]);
        object_set_scale(scene->toolbar->actions[i], (sfVector2f){0, 1});
        object_set_origin(scene->toolbar->actions[i], (sfVector2f){0, 70});
        scene_add_object(&scene->objects, object_create_from_image(
            KEY_ACTION, (loc_t){x + 20, 990 + 52}, KEY_ACTION_S));
        object_set_render_priority(scene->toolbar->actions[i], 100);
        object_set_render_priority(object_get_from_uuid(
            &scene->objects, KEY_ACTION), 101);
        x += 70;
    }
}

void add_stats_cpt(game *scene)
{
    scene_add_text(&scene->objects, textobject_create(
        STATS_MAXPV_TXT, (loc_t){170, 240}, "100"));
    textobject_set_size(textobject_get_from_uuid(
        &scene->objects, STATS_MAXPV_TXT), 20);
    scene_add_text(&scene->objects, textobject_create(
        STATS_DAMAGE_TXT, (loc_t){175, 340}, "25"));
    textobject_set_size(textobject_get_from_uuid(
        &scene->objects, STATS_DAMAGE_TXT), 20);
    scene_add_text(&scene->objects, textobject_create(
        STATS_SPEED_TXT, (loc_t){180, 440}, "1"));
    textobject_set_size(textobject_get_from_uuid(
        &scene->objects, STATS_SPEED_TXT), 20);
    scene_add_object(&scene->objects, object_create_from_image(
        INFO_SHIELD, (loc_t){44, 123}, INFO_SHIELD_S));
    scene_add_object(&scene->objects, object_create_from_image(
        INFO_DAMAGE, (loc_t){44, 223}, INFO_DAMAGE_S));
    scene_add_object(&scene->objects, object_create_from_image(
        INFO_SPEED, (loc_t){44, 323}, INFO_SPEED_S));
}

void add_stats(game *scene)
{
    scene_add_object(&scene->objects, object_create_from_image(
        MOUSE_STATE, (loc_t){1810, 30}, MOUSE_STATE_S));
    object_set_render_priority(object_get_from_uuid(
            &scene->objects, MOUSE_STATE), 103);
    scene_add_object(&scene->objects, object_create_from_image(
        PLAYER_STATS_BTN, (loc_t){30, 100}, PLAYER_STATS_BTN_S));
    object_set_render_priority(object_get_from_uuid(
            &scene->objects, PLAYER_STATS_BTN), 104);
    scene_add_object(&scene->objects, object_create_from_image(
        PLAYER_STATS, (loc_t){30, 120}, PLAYER_STATS_S));
    object_set_rect(object_get_from_uuid(&scene->objects, PLAYER_STATS),
    (sfIntRect){0, 0, 257, 0});
    scene_add_object(&scene->objects, object_create_from_image(
        INFO_DOLEX, (loc_t){44, 61}, INFO_DOLEX_S));
    scene_add_text(&scene->objects, textobject_create(
        DOLEX_TXT, (loc_t){200, 147}, "0"));
    object_set_render_priority(textobject_get_from_uuid(
            &scene->objects, DOLEX_TXT)->object, 106);
    add_stats_cpt(scene);
    stats(scene);
}

void add_gui(game *scene)
{
    SAO(&scene->objects, OCFI(PV_BACK, (loc_t){100, 30}, PV_BACK_S));
    SAO(&scene->objects, OCFI(PV, (loc_t){100, 30}, PV_S));
    SAO(&scene->objects, OCFI(TOOLBAR, (loc_t){610, 980}, TOOLBAR_S));
    SAO(&scene->objects, OCFI(
        TOOLXP_BACK, (loc_t){100, 50}, TOOL_XP_BACK_S));
    object_set_render_priority(object_get_from_uuid(
            &scene->objects, PV_BACK), 97);
    object_set_render_priority(object_get_from_uuid(
            &scene->objects, PV), 98);
    object_set_render_priority(object_get_from_uuid(
            &scene->objects, TOOLBAR), 99);
    object_set_render_priority(object_get_from_uuid(
            &scene->objects, TOOLXP_BACK), 100);
    add_toolxp(scene);
    add_toolbar(scene);
    add_stats(scene);
    add_quests(scene);
    add_settings_menu(scene);
}
