/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** planete_event.c
*/

#include <math.h>
#define p(a) (a) * (a)
#include "../../../../include/game/rpg.h"

void just_check(object_t *object);

void planete_angle(float px, float py, space_planete_t *pl)
{
    float sx = px - (1920 / 2);
    float sy = py - (1080 / 2);
    float ppx = 0;
    float ppy = 1;
    float a = acosf(sy / (sqrtf(p(sx) + p(sy)))) * 180 /
    M_PI * (px < (1920 / 2) ? 1 : -1)  + 45;
    sfSprite_setRotation(pl->object->sprite, a);
}

float my_mmap(float x, float a, float b, float c, float d)
{
    return (x - a) / (b - a) * (d - c) + c;
}

V2F ellep(all_planet_t *planete, SpaceShip *scene)
{
    float x = 0;
    float y = 0;

    planete->prog +=
        ((planete->speed * (ENGINE->delta_time / 45000)) * scene->ratio);
    planete->cs[0] = sinf(planete->prog);
    planete->cs[1] = cosf(planete->prog);
    planete->a.y = my_mmap(planete->cs[0], -1, 1, (1080 / 2) - planete->dist,
        (1080 / 2) + planete->dist);
    planete->b.x = my_mmap(planete->cs[1], -1, 1, (1920 / 2) - planete->dist,
        (1920 / 2) + planete->dist);
    x = (planete->a.x - planete->b.x) / 1.5;
    y = (planete->a.y - planete->b.y) / 3.5;
    return (V2F){x + (1920 / 2), y + (1080 / 2)};
}

static void place_text(space_planete_t *pl, sfVector2f mouse,
textobject_t *text, int size)
{
    sfFloatRect rect = sfText_getGlobalBounds(pl->desc->text);

    textobject_set_position(
        text, (sfVector2f){mouse.x + 10, mouse.y - rect.height - 10});
    textobject_set_size(text, size);
}

static void check_on_hover(space_planete_t *pl, SpaceShip *scene)
{
    sfVector2f pos = object_get_position(pl->object);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(ENGINE->window);
    sfFloatRect dec = sfText_getLocalBounds(pl->desc->text);
    str_t *str = str_create("");

    if (object_on_hover(pl->object, &just_check) && pl->is_active) {
        object_set_scale(pl->object, (sfVector2f){1.1, 1.1});
        if (scene->press) {
            pl->is_active = false;
            pl->desc->object->visible = true;
            pl->title->object->visible = true;
            pl->stats_speed->object->visible = true;
            pl->difficulty->object->visible = true;
            pl->icon_planet->visible = true;
            scene->lock = pl->lock;
            scene->n_stats += 1;
            scene->new_current = my_strdup(sfText_getString(pl->title->text));
            if (scene->lock)
                object_set_rect(OGFuuid_t(&scene->objects, 600),
                (sfIntRect){390, 0, 190, 68});
            else
                object_set_rect(OGFuuid_t(&scene->objects, 600),
                (sfIntRect){0, 0, 190, 68});
        }
    } else if (!object_on_hover(pl->object, &just_check) && !pl->is_active) {
        object_set_scale(pl->object, (sfVector2f){1, 1});
        if (scene->press) {
            pl->is_active = true;
            pl->desc->object->visible = false;
            pl->title->object->visible = false;
            pl->stats_speed->object->visible = false;
            pl->difficulty->object->visible = false;
            pl->icon_planet->visible = false;
            scene->n_stats -= 1;
        }
    }
    place_text(pl, (V2F){1560, 850}, pl->desc, 15);
    place_text(pl, (V2F){1680 - sfText_getGlobalBounds(
        pl->title->text).width / 2, 585}, pl->title, 30);
    str_add_float(str, (1 / pl->speed) * scene->ratio, 1);
    textobject_set_string(pl->stats_speed, str->str);
    place_text(pl, (V2F){1720 - sfText_getGlobalBounds(
        pl->stats_speed->text).width / 2, 665}, pl->stats_speed, 30);
    place_text(pl, (V2F){1755 - sfText_getGlobalBounds(
        pl->difficulty->text).width / 2, 730}, pl->difficulty, 25);
    OSP(pl->icon_planet, (V2F){1690, 920});
    sfSprite_setRotation(pl->icon_planet->sprite, sfSprite_getRotation(
        pl->object->sprite));
}

void event_planete(SpaceShip *scene_menu)
{
    space_planete_t *pl = scene_menu->planete;
    sfFloatRect pl_pos;
    sfFloatRect tx_pos;

    if (scene_menu->n_stats > 0)
        OGFuuid_t(&scene_menu->objects, 600)->visible = true;
    else
        object_set_visible(OGFuuid_t(&scene_menu->objects, 600), false);
    while (pl) {
        check_on_hover(pl, scene_menu);
        if (pl->id == -1) {
            sfSprite_rotate(pl->object->sprite, -1);
            pl = pl->next;
            continue;
        }
        V2F pos = ellep(pl->info, scene_menu);
        object_set_position(pl->object, pos);
        planete_angle(pos.x, pos.y, pl);
        pl_pos = sfSprite_getLocalBounds(pl->object->sprite);
        tx_pos = sfText_getLocalBounds(pl->text->text);
        put_pixel(scene_menu->bufsc, pos.x, pos.y, rgba(255, 255, 255, 255));
        pos.y += (pl_pos.height / 2);
        pos.x -= (tx_pos.width / 2);
        textobject_set_position(pl->text, pos);
        pl = pl->next;
    }
}
