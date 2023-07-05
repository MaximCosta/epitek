/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** ia.c
*/

#include "../../../../../include/game/rpg.h"

void ia_idle(game *scene, object_t *mob, enemy_t *data);
void ia_target(game *scene, object_t *mob, enemy_t *data);
void ia_attack(game *scene, object_t *mob, enemy_t *data);
bool ia_hit(game *scene, mob_t *mob, mob_t *tmp_sh);
void ia_movement(game *scene, mob_t *mob, mob_t *tmp_sh);
char *get_score(int n1, int n2);

void get_detection(game *scene, mob_t *mob, enemy_t *data)
{
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);
    sfVector2f player_pos = object_get_position(player);
    sfVector2f mob_pos = object_get_position(mob->mob);

    if (equal(data->type, "TARGET") ||
    equal(data->state, "ATTACK") || equal(data->state, "HIT"))
        return;
    if (player_pos.x >= mob_pos.x - data->detection &&
    player_pos.x <= mob_pos.x + data->detection &&
    player_pos.y >= mob_pos.y - data->detection &&
    player_pos.y <= mob_pos.y + data->detection)
        data->state = my_strdup("DETECTION");
    if (equal(data->state, "DETECTION") &&
    (player_pos.x < mob_pos.x - data->vision ||
    player_pos.x > mob_pos.x + data->vision) ||
    (player_pos.y < mob_pos.y - data->vision ||
    player_pos.y > mob_pos.y + data->vision))
        data->state = my_strdup("IDLE");
}

void get_attack(game *scene, mob_t *mob, enemy_t *data)
{
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);
    sfVector2f player_pos = object_get_position(player);
    sfVector2f mob_pos = object_get_position(mob->mob);
    player_pos = (sfVector2f){player_pos.x + 64, player_pos.y + 32};
    mob_pos = (sfVector2f){mob_pos.x + (data->dimension.x / 2),
    mob_pos.y + (data->dimension.y / 2)};

    if (equal(data->type, "BIG"))
        player_pos.y += 64;
    if (!equal(data->state, "DETECTION") ||
    !elapsed_time_milliseconds(mob->data->as,
    &mob->data->dattack.time, &mob->data->dattack.saved) ||
    equal(data->state, "HIT"))
        return;
    if (player_pos.x >= mob_pos.x - data->distance_attack &&
    player_pos.x <= mob_pos.x + data->distance_attack &&
    player_pos.y >= mob_pos.y - data->distance_attack &&
    player_pos.y <= mob_pos.y + data->distance_attack)
        data->state = my_strdup("ATTACK");
}

void update_text(game *scene, mob_t *mob)
{
    sfVector2f pos = object_get_position(mob->mob);

    if (!equal(mob->data->type, "PHANTOM"))
        pos.y -= mob->data->dimension.y;
    textobject_set_string(mob->data->pv_text, get_score(mob->data->pv,
    mob->data->pvmax));
    textobject_set_position(mob->data->pv_text, pos);
    textobject_set_size(mob->data->pv_text, 10);
}

void ia_process(game *scene, mob_t *mob, mob_t *tmp_sh)
{
    if (equal(mob->data->state, "HIT"))
        if (ia_hit(scene, mob, tmp_sh))
            return;
    get_detection(scene, mob, mob->data);
    get_attack(scene, mob, mob->data);
    if (equal(mob->data->state, "DETECTION"))
        ia_movement(scene, mob, tmp_sh);
    if (equal(mob->data->state, "IDLE"))
        ia_idle(scene, mob->mob, mob->data);
    if (equal(mob->data->state, "DETECTION"))
        ia_target(scene, mob->mob, mob->data);
    if (equal(mob->data->state, "ATTACK"))
        ia_attack(scene, mob->mob, mob->data);
    update_text(scene, mob);
}

void ia(game *scene)
{
    mob_t *tmp;
    mob_t *tmp_sh;

    if (scene->mobs == NULL)
        return;
    tmp = scene->mobs;
    tmp_sh = scene->mobs;
    for (; tmp != NULL; tmp = tmp->next)
        if (!scene->player->PAUSE)
            ia_process(scene, tmp, tmp_sh);
}
