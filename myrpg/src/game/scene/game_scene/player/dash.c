/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** dash.c
*/

#include "../../../../../include/game/rpg.h"

void player_reinit(game *scene, object_t *map, object_t *player)
{
    if (object_get_rect(player).top < 448 ||
    object_get_rect(player).left != 256)
        return;

    object_set_rect(player, (sfIntRect){0, 0, 128, 64});
        object_set_position(player, (sfVector2f){
        object_get_position(player).x + scene->dash_move[2],
        object_get_position(player).y});
    scene->player->DASH = false;
}

void dash_move(game *scene, object_t *map, object_t *player)
{
    mob_t *tmp = scene->mobs;
    object_t *b_map = OGFuuid_t(&scene->objects, MAP_BACK);
    flitem_t *tmp_fil = scene->flitem;

    OSP(map, (sfVector2f){OGP(map).x + scene->dash_move[0], OGP(map).y});
    OSP(player, (sfVector2f){OGP(player).x + scene->dash_move[1],
    OGP(player).y});
    for (; tmp != NULL; tmp = tmp->next)
        OSP(tmp->mob, (sfVector2f){OGP(tmp->mob).x + scene->dash_move[0],
        OGP(tmp->mob).y});
    for (; tmp_fil != NULL; tmp_fil = tmp_fil->next)
        OSP(tmp_fil->data->item, (sfVector2f){
        OGP(tmp_fil->data->item).x + scene->dash_move[0],
        OGP(tmp_fil->data->item).y});
    OSP(scene->trader->trader, (sfVector2f){
        OGP(scene->trader->trader).x + scene->dash_move[0],
        OGP(scene->trader->trader).y});
    OSP(b_map, (V2F){OGP(b_map).x + scene->dash_move[0], OGP(b_map).y});
}

void player_dash(game *scene, object_t *map, float speed)
{
    static DeltaTime delta = (DeltaTime){.saved = 0.00, .time = 0.00};
    static DeltaTime move = (DeltaTime){.saved = 0.00, .time = 0.00};
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);

    if (!scene->player->DASH || scene->player->ATTACK)
        return;
    if (elapsed_time_milliseconds(100, &delta.time, &delta.saved)) {
        object_set_rect(player, (sfIntRect){256,
        object_get_rect(player).top + 64, 128, 64});
    }
    if (elapsed_time_milliseconds(10, &move.time, &move.saved)) {
        if ((object_get_position(map).x < -128 &&
        object_get_position(player).x <= 960)
        || (object_get_position(map).x + 1152 > 0 &&
        object_get_position(player).x >= 960))
            dash_move(scene, map, player);
    }
    player_reinit(scene, map, player);
}
