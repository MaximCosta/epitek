/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** create_object_menu.c
*/

#include "../../../../../include/game/rpg.h"

static const char *BACKGROUND_MENU_S = "./assets/menu/BackgroundMenu.png";
static const char *PLAY_BUTTON_S = "./assets/menu/PlayButton.png";
static const char *MULTIPLAYER_BUTTON_S =
    "./assets/menu/MultiplayerButton.png";
static const char *BACK_TO_MENU_S = "./assets/menu/BackToMenu.png";
static const char *BLACKSCREEN_M_S = "./assets/main/BlackTransition.png";
static const char *TITLE_S = "./assets/menu/Title.png";
static const char *HOW_TO_PLAY_S = "./assets/HowToPlay/How_To_Play.png";
static const char *FONDU_S = "./assets/HowToPlay/fondu.png";
static const char *HTP_DRAW_S = "./assets/HowToPlay/HTP_draw.png";


void create_htp(MenuScene *scene)
{
    object_t *fondu = OCFI(FONDU, (loc_t){600, 100}, FONDU_S);
    object_t *how_to_play = OCFI(HOW_TO_PLAY, (loc_t){600, 100}, HOW_TO_PLAY_S);
    object_t *htp_draw = OCFI(HTP_DRAW, (loc_t){100, 100}, HTP_DRAW_S);

    SAO(&scene->objects, fondu);
    SAO(&scene->objects, how_to_play);
    SAO(&scene->objects, htp_draw);
    fondu->visible = false;
    how_to_play->visible = false;
    htp_draw->visible = false;
    object_set_render_priority(fondu, 11);
    object_set_render_priority(how_to_play, 10);
    object_set_render_priority(htp_draw, 10);
    object_set_rect(how_to_play, (sfIntRect){0, 0, 900, 819});
}

void initiate_object(MenuScene *menu_scene)
{
    object_t *play_button = NULL;
    object_t *multi_button = NULL;
    object_t *back_button = NULL;

    play_button = object_get_from_uuid(&menu_scene->objects, PLAY_BUTTON);
    multi_button =
        object_get_from_uuid(&menu_scene->objects, MULTIPLAYER_BUTTON);
    back_button = object_get_from_uuid(&menu_scene->objects, BACK_TO_MENU);
    object_set_rectlist((object_t *[2]){play_button, multi_button},
        (sfIntRect){0, 0, object_get_origin_size(play_button).x / 3,
            object_get_size(play_button).y},
        2);
    object_set_rect(back_button,
        (sfIntRect){0, 0, object_get_origin_size(back_button).x / 3,
            object_get_size(back_button).y});
}

void create_object_menu(MenuScene *menu_scene)
{
    scene_add_object(&menu_scene->objects,
        object_create_from_image(
            BACKGROUND_MENU, (loc_t){-22, -22}, BACKGROUND_MENU_S));
    scene_add_object(&menu_scene->objects,
        object_create_from_image(
            PLAY_BUTTON, (loc_t){537, 257}, PLAY_BUTTON_S));
    scene_add_object(&menu_scene->objects,
        object_create_from_image(
            MULTIPLAYER_BUTTON, (loc_t){987, 257}, MULTIPLAYER_BUTTON_S));
    scene_add_object(&menu_scene->objects,
        object_create_from_image(
            BACK_TO_MENU, (loc_t){538, 680}, BACK_TO_MENU_S));
    scene_add_object(&menu_scene->objects,
        object_create_from_image(TITLE, (loc_t){538, 150}, TITLE_S));
    scene_add_object(&menu_scene->objects,
        object_create_from_image(
            BLACKSCREEN_M, (loc_t){0, 0}, BLACKSCREEN_M_S));
    object_set_render_priority(
        object_get_from_uuid(&menu_scene->objects, BLACKSCREEN_M), 100);
    initiate_object(menu_scene);
    create_htp(menu_scene);
}
