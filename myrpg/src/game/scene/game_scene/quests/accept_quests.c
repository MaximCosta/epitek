/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** accept_quests.c
*/

#include "../../../../../include/game/rpg.h"

void just_check(object_t *object);

void open_msg(game *scene, int *i, object_t *msg, sfIntRect msg_r)
{
    static DeltaTime delta = {.time = 0.00, .saved = 0.00};
    float speed = 0.001 * ENGINE->delta_time;

    if (msg_r.width < 542)
        object_set_rect(msg, (sfIntRect){msg_r.left, msg_r.top,
        msg_r.width + speed, msg_r.height});
    else
        object_set_rect(msg, (sfIntRect){0, 0, 542, 48});
    if (elapsed_time_milliseconds(5000, &delta.time, &delta.saved))
        *i = 1;
}

void animation_msg_quest(game *scene)
{
    static int i = 0;
    float speed = 0.001 * ENGINE->delta_time;
    object_t *msg = object_get_from_uuid(&scene->objects, ACCEPT_MSG);
    object_t *accept = object_get_from_uuid(&scene->objects, ACCEPT_QUEST);
    sfIntRect msg_r = object_get_rect(msg);

    if (!scene->quests->main_quest_active || i == 1) {
        if (msg_r.width > 2)
            object_set_rect(msg, (sfIntRect){msg_r.left, msg_r.top,
            msg_r.width - speed, msg_r.height});
        else
            object_set_rect(msg, (sfIntRect){0, 0, 0, 48});
        return;
    }
    open_msg(scene, &i, msg, msg_r);
}

void update_accept_btn(game *scene, bool visible, object_t *accept)
{
    object_t *accept_btn = OGFuuid_t(&scene->objects, QUESTS_ACCPET_BTN);

    if (visible) {
        OSP(accept_btn, (V2F){OGP(accept).x + 161, OGP(accept).y});
        object_set_visible(accept_btn, true);
    } else
        object_set_visible(accept_btn, false);
    if (object_on_hover(accept_btn, &just_check) && scene->player->PAUSE)
        object_set_rect(accept_btn, (sfIntRect){68, 0, 68, 33});
    else
        object_set_rect(accept_btn, (sfIntRect){0, 0, 68, 33});
    animation_msg_quest(scene);
}

bool clic_for_accept(game *scene, bool visible, object_t *accept)
{
    object_t *accept_btn = OGFuuid_t(&scene->objects, QUESTS_ACCPET_BTN);
    static int i = 0;

    update_accept_btn(scene, visible, accept);
    if (visible && object_on_hover(accept_btn, &just_check) &&
    scene->mouse_press) {
        scene->quests->main_quest_active = true;
        scene->quests->n_quests += 1;
        scene->mouse_press = false;
        if (object_get_rect(accept).top == 33 && i > 0)
            scene_change(SPACESHIP);
        i += 1;
    }
    if (scene->quests->n_emeraude >= 1 && scene->quests->n_lapis >= 1 &&
    scene->quests->n_redstone >= 1) {
        object_set_rect(accept, (sfIntRect){0, 33, 229, 33});
        return true;
    }
    return false;
}

void accpet_quests(game *scene)
{
    static bool hg = false;
    object_t *accept = object_get_from_uuid(&scene->objects, ACCEPT_QUEST);
    object_t *map = object_get_from_uuid(&scene->objects, BACKGROUND_MAP);
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);
    V2F player_p = OGP(player);
    V2F map_p = OGP(map);
    V2F accept_p = OGP(accept);

    OSP(accept, (V2F){map_p.x + 1350, map_p.y + 1370});
    accept_p = OGP(accept);
    accept_p.x += 120;
    accept_p.y += 60;
    if ((accept_p.x > 950 && accept_p.x < 970
    && accept_p.y > 530 && accept_p.y < 550) &&
    (scene->quests->main_quest_active == false || hg == true))
        object_set_visible(accept, true);
    else
        object_set_visible(accept, false);
    hg = clic_for_accept(scene, object_is_visible(accept), accept);
}
