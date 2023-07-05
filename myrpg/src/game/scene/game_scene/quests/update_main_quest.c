/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** update_main_quest.c
*/

#include "../../../../../include/game/rpg.h"

void just_check(object_t *object);
void objectives_animation(game *scene);

void mouse_quests(game *scene, object_t *main_q, bool visible)
{
    bool on = object_on_hover(main_q, &just_check);
    bool click = scene->quests->on_click;

    if (on && visible) {
        object_set_rect(main_q, (sfIntRect){0, 39, 224, 39});
        if (scene->mouse_press && click) {
            scene->quests->on_click = false;
            scene->mouse_press = false;
        } else if (scene->mouse_press && !click) {
            scene->quests->on_click = true;
            scene->mouse_press = false;
        }
    } else
        object_set_rect(main_q, (sfIntRect){0, 0, 224, 39});
    objectives_animation(scene);
}

V2F get_player(game *scene, V2F window)
{
    object_t *player = OGFuuid_t(&scene->objects, PLAYER);
    object_t *map = OGFuuid_t(&scene->objects, BACKGROUND_MAP);
    V2F p_map = OGP(map);
    V2F pos = OGP(player);

    if (OGP(map).x + 1280 < 0 || OGP(player).x < 960
    || OGP(map).x > 0 && OGP(player).x > 960 )
        window = OGP(player);
    if (object_get_scale(player).x < 0)
        window.x += 33;
    return window;
}

void update_text_distance(game *scene, textobject_t *distance, V2F main_qp)
{
    object_t *accept = object_get_from_uuid(&scene->objects, ACCEPT_QUEST);
    V2F accept_p = OGP(accept);
    V2F window = {960, 540};
    int distance_to_main = 0;

    accept_p.x += 120;
    accept_p.y += 60;
    window = get_player(scene, window);
    if (accept_p.x > window.x)
        distance_to_main = accept_p.x - window.x;
    else
        distance_to_main = window.x - accept_p.x;
    if (accept_p.y > window.y)
        distance_to_main += accept_p.y - window.y;
    else
        distance_to_main += window.y - accept_p.y;
    if (distance_to_main/10 > 1)
        textobject_set_string(distance, my_itoa(distance_to_main/10, 0));
    else
        textobject_set_string(distance, "0");
    textobject_set_position(distance, (V2F){main_qp.x + 150, main_qp.y + 10});
}

void update_objectives(game *scene, object_t *main_q, V2F main_qp)
{
    object_t *objectives = OGFuuid_t(&scene->objects, OBJECTIVES_QUEST);

    main_qp.y += 50;
    OSP(objectives, main_qp);
}

void update_main_quest(game *scene)
{
    object_t *main_q = OGFuuid_t(&scene->objects, MAIN_QUEST);
    object_t *quests = OGFuuid_t(&scene->objects, PLAYER_QUESTS);
    textobject_t *distance = textobject_get_from_uuid(&scene->objects,
        MAIN_QUEST_DISTANCE);
    sfIntRect quests_rect = object_get_rect(quests);
    V2F quests_p = OGP(quests);

    quests_p = (V2F){quests_p.x + 15, quests_p.y + 90};
    OSP(main_q, (V2F){quests_p.x, quests_p.y});
    if (quests_rect.height > 100 && scene->quests->main_quest_active) {
        object_set_visible(main_q, true);
        object_set_visible(distance->object, true);
    } else {
        object_set_visible(main_q, false);
        object_set_visible(distance->object, false);
    }
    mouse_quests(scene, main_q, object_is_visible(main_q));
    update_text_distance(scene, distance, OGP(main_q));
    update_objectives(scene, main_q, OGP(main_q));
}