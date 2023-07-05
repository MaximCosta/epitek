/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** trader.c
*/

#include "../../../../../include/game/rpg.h"

void trader_update_rec(game *scene, textobject_t *wallet, sfVector2f wallet_p,
sfVector2f pos);
void update_payment(game *scene);

void trader_idle(trader_t *trad)
{
    static DeltaTime delta = {.time = 0.00, .saved = 0.00};
    sfIntRect rect = object_get_rect(trad->trader);

    if (elapsed_time_milliseconds(110, &delta.time, &delta.saved))
        object_set_rect(trad->trader, (sfIntRect){
            rect.left + 64, rect.top, rect.width, rect.height});
    if (rect.left >= 192)
        object_set_rect(trad->trader, (sfIntRect){0, 0, 64, 64});
}

void trader_movement(trader_t *trad)
{
    static DeltaTime delta = {.time = 0.00, .saved = 0.00};
    sfIntRect rect = object_get_rect(trad->trader);

    if (elapsed_time_milliseconds(110, &delta.time, &delta.saved))
        object_set_rect(trad->trader, (sfIntRect){
            rect.left + 64, 64, rect.width, rect.height});
    if (rect.left >= 256)
        object_set_rect(trad->trader, (sfIntRect){0, 64, 64, 64});
}

void update_message(game *scene)
{
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);
    object_t *msg = object_get_from_uuid(&scene->objects, TRADER_MESSAGE);
    sfVector2f pos = object_get_position(scene->trader->trader);
    sfFloatRect rect_player = sfSprite_getGlobalBounds(player->sprite);
    sfFloatRect rect_trader = sfSprite_getGlobalBounds(
        scene->trader->trader->sprite);

    if (sfFloatRect_intersects(&rect_player, &rect_trader, NULL) == sfTrue) {
        object_set_visible(msg, true);
        if (scene->trader->click && !scene->trader->active) {
            scene->trader->click = false;
            scene->trader->active = true;
            scene->player->PAUSE = true;
        }
        if (scene->trader->click && scene->trader->active) {
            scene->trader->click = false;
            scene->trader->active = false;
            scene->player->PAUSE = false;
        }
    } else
        object_set_visible(msg, false);
    object_set_position(msg, (sfVector2f){pos.x - 32, pos.y - 25});
}

void update_rect(game *scene)
{
    sfVector2f pos = object_get_position(scene->trader->trader_panel);
    textobject_t *wallet = textobject_get_from_uuid(&scene->objects, WALLET);
    sfVector2f wallet_p = textobject_get_position(wallet);

    if (scene->player->money != 0)
        textobject_set_string(wallet, my_itoa(scene->player->money, 0));
    else
        textobject_set_string(wallet, "0");
    trader_update_rec(scene, wallet, wallet_p, pos);
}

void update_trader(game *scene)
{
    static bool movement = false;

    update_payment(scene);
    update_rect(scene);
    update_message(scene);
    if (scene->player->PAUSE)
        return;
    if (!movement)
        trader_idle(scene->trader);
    else
        trader_movement(scene->trader);
}
