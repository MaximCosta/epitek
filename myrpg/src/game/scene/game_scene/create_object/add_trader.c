/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** add_trader.c
*/

#include "../../../../../include/game/rpg.h"

static const char *TRADER_S = "./assets/GameScene/Enemy/trader.png";
static const char *TRADER_MESSAGE_S = "./assets/GameScene/GUI/"
                                      "trader_message.png";
static const char *TRADER_PANEL_S = "./assets/GameScene/GUI/trader_panel.png";
static const char *TRADER_INFO_BTN_S = "./assets/GameScene/GUI/"
                                       "trader_info_btn.png";
static const char *TARDER_INFO_S = "./assets/GameScene/GUI/trader_info.png";
static const char *TARDER_PAYMENT_S = "./assets/GameScene/GUI/payment.png";

void add_trader_and_wallet(game *scene)
{
    textobject_t *wallet =
        textobject_create(WALLET, (loc_t){2061, 308}, "1 000");
    object_t *info_btn = OCFI(
        TRADER_INFO_BTN, (loc_t){2338, 142}, TRADER_INFO_BTN_S);
    object_t *trader_info = OCFI(
        TRADER_INFO, (loc_t){1935, 300}, TARDER_INFO_S);
    scene_add_text(&scene->objects, wallet);
    sfText_setColor(wallet->text, sfBlack);
    textobject_set_size(wallet, 15);
    SAO(&scene->objects, info_btn);
    SAO(&scene->objects, trader_info);
    object_set_render_priority(wallet->object, 131);
    object_set_render_priority(info_btn, 132);
    object_set_render_priority(trader_info, 160);
    object_set_rect(trader_info, (sfIntRect){0, 0, 474, 0});
}

void add_trader_2(game *scene)
{
    static int idd = 2000;
    static int priority = 133;
    int y = 356;

    scene->trader->active = false;
    scene->trader->click = false;
    add_trader_and_wallet(scene);
    scene->trader->payment = malloc(sizeof(object_t *) * 4);
    for (int i = 0; i < 4; i++) {
        scene->trader->payment[i] = OCFI(
            idd++, (loc_t){1937, y}, TARDER_PAYMENT_S);
        SAO(&scene->objects, scene->trader->payment[i]);
        object_set_render_priority(scene->trader->payment[i], priority++);
        y += 150;
    }
}

void add_trader(game *scene)
{
    scene->trader = malloc(sizeof(trader_t));

    scene->trader->trader = OCFI(TRADER, (loc_t){1800, -600}, TRADER_S);
    SAO(&scene->objects, scene->trader->trader);
    object_set_scale(scene->trader->trader, (sfVector2f){2, 2});
    object_set_rect(scene->trader->trader, (sfIntRect){0, 0, 64, 64});
    SAO(&scene->objects,
        OCFI(TRADER_MESSAGE, (loc_t){960, 540}, TRADER_MESSAGE_S));
    object_set_render_priority(
        OGFuuid_t(&scene->objects, TRADER_MESSAGE), 50);
    object_set_visible(
        OGFuuid_t(&scene->objects, TRADER_MESSAGE), false);
    scene->trader->trader_panel = OCFI(
        TRADER_PANEL, (loc_t){2421, 540}, TRADER_PANEL_S);
    SAO(&scene->objects, scene->trader->trader_panel);
    object_set_render_priority(scene->trader->trader_panel, 130);
    object_set_origin(scene->trader->trader_panel, (sfVector2f){501, 417});
    add_trader_2(scene);
}
