/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** how_to_play.c
*/

#include "../../../../../include/game/rpg.h"

void just_check(object_t *object);

void htp_event(MenuScene *scene)
{
    object_t *htp = OGFuuid_t(&scene->objects, HOW_TO_PLAY);
    sfTexture *texture = sfSprite_getTexture(htp->sprite);
    sfVector2u size = sfTexture_getSize(texture);
    sfIntRect rect = OGR(htp);
    static float i = 0.0;

    if (!object_on_hover(htp, &just_check))
        return;
    if (scene->wheel < 0 && OGR(htp).top +
        (int)OGR(htp).height < (int)size.y) {
        OSR(htp, (sfIntRect){0, OGR(htp).top +
        (0.001 * ENGINE->delta_time), rect.width, rect.height});
        i += 0.00001 * ENGINE->delta_time;
    } else if (scene->wheel == 1 && OGR(htp).top > 0) {
        OSR(htp, (sfIntRect){0, OGR(htp).top -
        (0.001 * ENGINE->delta_time), rect.width, rect.height});
        i += 0.00001 * ENGINE->delta_time;
    }
    if (i > 1) {
        scene->wheel = 32;
        i = 0;
    }
}

void how_to_play(MenuScene *scene)
{
    OGFuuid_t(&scene->objects, PLAY_BUTTON)->visible = false;
    OGFuuid_t(&scene->objects, MULTIPLAYER_BUTTON)->visible = false;
    OGFuuid_t(&scene->objects, BACK_TO_MENU)->visible = false;
    OGFuuid_t(&scene->objects, TITLE)->visible = false;
    OGFuuid_t(&scene->objects, HOW_TO_PLAY)->visible = true;
    OGFuuid_t(&scene->objects, HTP_DRAW)->visible = true;
    OGFuuid_t(&scene->objects, FONDU)->visible = true;
    OSR(OGFuuid_t(&scene->objects, CURSOR_M), (sfIntRect){0, 0, 32, 32});
    htp_event(scene);
}
