/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** add_quests.c
*/

#include "../../../../../include/game/rpg.h"

static const char *QUESTS_BTN_S = "./assets/GameScene/GUI/quests_btn.png";
static const char *PLAYER_QUESTS_S =
"./assets/GameScene/GUI/player_quests.png";
static const char *ACCEPT_QUEST_S = "./assets/GameScene/GUI/quest_accept.png";
static const char *MAIN_QUEST_S = "./assets/GameScene/GUI/main_quest.png";
static const char *OBJECTIVES_QUEST_S = "./assets/GameScene/GUI/"
"objectives_main_quest.png";
static const char *INDICATOR_S = "./assets/GameScene/GUI/indicator.png";
static const char *QUESTS_ACCPET_BTN_S = "./assets/GameScene/GUI/"
"quest_accept_btn.png";
static const char *ACCEPT_MSG_S = "./assets/GameScene/GUI/quest_msg.png";

void add_quests_accept(game *scene)
{
    object_t *accpet_btn = NULL;
    object_t *accept_msg = NULL;

    scene_add_object(&scene->objects, object_create_from_image(
        QUESTS_ACCPET_BTN, (loc_t){0, 0}, QUESTS_ACCPET_BTN_S));
    accpet_btn = OGFuuid_t(&scene->objects, QUESTS_ACCPET_BTN);
    scene_add_object(&scene->objects, object_create_from_image(
        ACCEPT_MSG, (loc_t){689, 30}, ACCEPT_MSG_S));
    accept_msg = OGFuuid_t(&scene->objects, ACCEPT_MSG);
    object_set_render_priority(accpet_btn, 104);
    object_set_render_priority(accept_msg, 105);
    object_set_rect(accept_msg, (sfIntRect){0, 0, 0, 48});
    object_set_rect(accpet_btn, (sfIntRect){0, 0, 68, 33});
    object_set_visible(accpet_btn, false);
}

void add_text_quest(game *scene)
{
    textobject_t *emeraude = NULL;
    textobject_t *lapis = NULL;
    textobject_t *redstone = NULL;

    scene_add_text(&scene->objects, textobject_create(
        LAPIS_TEXT, (loc_t){960, 540}, "0/1"));
    scene_add_text(&scene->objects, textobject_create(
        EMERAUDE_TEXT, (loc_t){960, 540}, "0/1"));
    scene_add_text(&scene->objects, textobject_create(
        REDSTONE_TEXT, (loc_t){960, 540}, "0/1"));
    emeraude = textobject_get_from_uuid(&scene->objects, EMERAUDE_TEXT);
    redstone = textobject_get_from_uuid(&scene->objects, REDSTONE_TEXT);
    lapis = textobject_get_from_uuid(&scene->objects, LAPIS_TEXT);
    textobject_set_size(emeraude, 10);
    textobject_set_size(redstone, 10);
    textobject_set_size(lapis, 10);
    object_set_render_priority(emeraude->object, 125);
    object_set_render_priority(lapis->object, 126);
    object_set_render_priority(redstone->object, 127);
    add_quests_accept(scene);
}

void add_objectives(game *scene)
{
    object_t *objectives = NULL;
    object_t *indicator = NULL;

    scene_add_object(&scene->objects, object_create_from_image(
    OBJECTIVES_QUEST, (loc_t){0, 0}, OBJECTIVES_QUEST_S));
    objectives = object_get_from_uuid(&scene->objects, OBJECTIVES_QUEST);
    object_set_render_priority(objectives, 124);
    scene_add_object(&scene->objects, object_create_from_image(
        INDICATOR, (loc_t){905, 450}, INDICATOR_S));
    indicator = object_get_from_uuid(&scene->objects, INDICATOR);
    object_set_scale(indicator, (V2F){0.05, 0.05});
    object_set_render_priority(indicator, 100);
    object_set_rect(objectives, (sfIntRect){0, 0, 224, 0});
    add_text_quest(scene);
}

void add_quests_no_gui(game *scene)
{
    object_t *quest = NULL;
    object_t *main_q = NULL;
    textobject_t *distance = NULL;

    scene_add_object(&scene->objects, object_create_from_image(
        ACCEPT_QUEST, (loc_t){900, 400}, ACCEPT_QUEST_S));
    quest = object_get_from_uuid(&scene->objects, ACCEPT_QUEST);
    object_set_rect(quest, (sfIntRect){0, 0, 229, 33});
    object_set_render_priority(quest, 100);
    scene_add_object(&scene->objects, object_create_from_image(
        MAIN_QUEST, (loc_t){900, 400}, MAIN_QUEST_S));
    main_q = OGFuuid_t(&scene->objects, MAIN_QUEST);
    object_set_render_priority(main_q, 122);
    object_set_rect(main_q, (sfIntRect){0, 0, 224, 39});
    scene_add_text(&scene->objects, textobject_create(
        MAIN_QUEST_DISTANCE, (loc_t){0, 0}, "1000"));
    distance = textobject_get_from_uuid(&scene->objects, MAIN_QUEST_DISTANCE);
    object_set_render_priority(distance->object, 123);
    textobject_set_size(distance, 15);
}

void add_quests(game *scene)
{
    scene_add_object(&scene->objects, object_create_from_image(
        QUESTS_BTN, (loc_t){30, 130}, QUESTS_BTN_S));
    object_set_render_priority(object_get_from_uuid(&scene->objects,
        QUESTS_BTN), 120);
    object_set_rect(object_get_from_uuid(&scene->objects, QUESTS_BTN),
        (sfIntRect){0, 0, 257, 20});
    scene_add_object(&scene->objects, object_create_from_image(
        PLAYER_QUESTS, (loc_t){30, 150}, PLAYER_QUESTS_S));
    object_set_render_priority(object_get_from_uuid(&scene->objects,
        PLAYER_QUESTS), 121);
    object_set_rect(object_get_from_uuid(&scene->objects, PLAYER_QUESTS),
        (sfIntRect){0, 0, 257, 400});
    object_set_rect(object_get_from_uuid(&scene->objects, PLAYER_QUESTS),
    (sfIntRect){0, 0, 257, 0});
    add_quests_no_gui(scene);
    add_objectives(scene);
}
