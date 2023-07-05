/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** add_gui.c
*/

#include "../../../../../include/game/rpg.h"

static const char *TOOL_XP_BACK_S = "./assets/GameScene/GUI/toolxp1.png";
static const char *TOOL_XP_FRONT_S = "./assets/GameScene/GUI/toolxp2.png";
static const char *PLAYER_ICON_S =
    "./assets/GameScene/GUI/profile/profile.png";
static const char *PLAYER_PROFILE_GUI_S =
    "./assets/GameScene/GUI/profile/profile_gui.png";
static const char *MOUSE_STATE_S = "./assets/GameScene/GUI/mouse_state.png";
static const char *PROFILE_NAME_EDIT_S =
    "./assets/GameScene/GUI/profile/profile_name_edit.png";
static const char *PLAYER_SKIN =
    "./assets/GameScene/player/player.png";

void add_gui_profile_player(game *scene)
{
    object_t *player_profile = object_create_from_image(PLAYER_PROFILE_GUI_PLAYER,
                                                        (loc_t){WIDTH / 2 - 220, HEIGHT / 2 - 160}, PLAYER_SKIN);

    object_set_rect(player_profile, (sfIntRect){0, 0, 64, 64});
    object_set_scale(player_profile, (sfVector2f){10, 10});
    object_set_centered_origin(player_profile);
    object_set_visible(player_profile, false);
    object_set_render_priority(player_profile, 129);
    scene_add_object(&scene->objects, player_profile);
}

void add_gui_profile(game *scene)
{
    object_t *profile_gui_o = object_create_from_image(PLAYER_PROFILE_GUI,
                                                       (loc_t){WIDTH / 2, HEIGHT / 2}, PLAYER_PROFILE_GUI_S);
    object_t *profile_gui_edit_name_o = object_create_from_image(
        PLAYER_PROFILE_GUI_NAME_EDIT,
        (loc_t){WIDTH / 1.5 - 248, HEIGHT / 3 - 108}, PROFILE_NAME_EDIT_S);

    object_set_centered_origin(profile_gui_o);
    object_set_visible(profile_gui_o, false);
    object_set_render_priority(profile_gui_o, 128);
    scene_add_object(&scene->objects, profile_gui_o);
    object_set_rect(profile_gui_edit_name_o, (sfIntRect){0, 0, 391, 24});
    object_set_centered_origin(profile_gui_edit_name_o);
    object_set_visible(profile_gui_edit_name_o, false);
    object_set_render_priority(profile_gui_edit_name_o, 129);
    scene_add_object(&scene->objects, profile_gui_edit_name_o);
    add_gui_profile_player(scene);
}

void add_toolxp(game *scene)
{
    object_t *profile_o = object_create_from_image(
        PLAYER_ICON, (loc_t){30, 30}, PLAYER_ICON_S);

    scene_add_object(&scene->objects,
                     object_create_from_image(
                         TOOLXP_FRONT, (loc_t){100, 50}, TOOL_XP_FRONT_S));
    object_set_render_priority(
        object_get_from_uuid(&scene->objects, TOOLXP_FRONT), 101);
    scene_add_object(&scene->objects, profile_o);
    object_set_rect(profile_o, (sfIntRect){0, 0, 48, 48});
    object_set_render_priority(
        object_get_from_uuid(&scene->objects, PLAYER_ICON), 102);
    object_set_scale(object_get_from_uuid(&scene->objects, TOOLXP_FRONT),
                     (sfVector2f){0, 1});
    add_gui_profile(scene);
}