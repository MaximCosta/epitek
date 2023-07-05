/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** update_payment.c
*/

#include "../../../../../include/game/rpg.h"

#define SPEED (0.001 * ENGINE->delta_time)

void just_check(object_t *object);

bool mouse_insides(object_t *object, sfIntRect rect);

void rect_payment(game *scene, object_t *payment)
{
    sfIntRect rect = object_get_rect(payment);
    sfIntRect n_rect = rect;
    static bool active = false;

    n_rect.width = 458;
    if (mouse_insides(payment, n_rect) && rect.width < 458) {
        object_set_rect(payment, (sfIntRect){rect.left, rect.top,
        rect.width + SPEED, rect.height});
    } else if (!mouse_insides(payment, n_rect) && rect.width > 0)
        object_set_rect(payment, (sfIntRect){rect.left, rect.top,
        rect.width - SPEED, rect.height});
    if (mouse_insides(payment, n_rect) && rect.width >= 458)
        object_set_rect(payment, (sfIntRect){0, 0, 458, 124});
    else if (!mouse_insides(payment, n_rect) && rect.width <= 5)
        object_set_rect(payment, (sfIntRect){0, 0, 0, 124});
}

void slide_payment(game *scene, object_t *payment)
{
    object_t *info = object_get_from_uuid(&scene->objects, TRADER_PANEL);
    V2F pos = OGP(info);
    V2F p_pay = OGP(payment);

    if (scene->trader->active && pos.x > 1920)
        OSP(payment, (V2F){p_pay.x - SPEED, p_pay.y});
    if (!scene->trader->active && pos.x < 2421)
        OSP(payment, (V2F){p_pay.x + SPEED, p_pay.y});
}

void update_payment(game *scene)
{
    for (int i = 0; i < 4; i++) {
        slide_payment(scene, scene->trader->payment[i]);
        rect_payment(scene, scene->trader->payment[i]);
    }
}
