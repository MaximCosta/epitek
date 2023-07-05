/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** main_quest_animation.c
*/

#include "../../../../../include/game/rpg.h"

void indicator_visual(game *scene, object_t *indicator)
{
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);
    sfFloatRect p_rect = sfSprite_getGlobalBounds(player->sprite);
    sfFloatRect i_rect = sfSprite_getGlobalBounds(indicator->sprite);
    sfColor color = {255, 255, 255, 255};

    if (sfFloatRect_intersects(&p_rect, &i_rect, NULL) == sfTrue)
        color = sfColor_fromRGBA(255, 255, 255, 100);
    else
        color = sfColor_fromRGBA(255, 255, 255, 255);
    sfSprite_setColor(indicator->sprite, color);
}

void quests_indicator(game *scene)
{
    object_t *indicator = OGFuuid_t(&scene->objects, INDICATOR);
    object_t *map = object_get_from_uuid(&scene->objects, BACKGROUND_MAP);
    V2F map_p = OGP(map);
    float speed = 0.00001 * ENGINE->delta_time;
    static V2F indicator_p = {1443, 1425};
    static int path = 0;

    if (path == 0 && indicator_p.y > 1420)
        indicator_p.y -= speed;
    else if (path == 0 && indicator_p.y <= 1420)
        path = 1;
    if (path == 1 && indicator_p.y < 1430)
        indicator_p.y += speed;
    else if (path == 1 && indicator_p.y >= 1430)
        path = 0;
    OSP(indicator, (V2F){map_p.x + indicator_p.x, map_p.y + indicator_p.y});
    indicator_visual(scene, indicator);
}

void objectives_animation(game *scene)
{
    float speed = 0.001 * ENGINE->delta_time;
    object_t *objective = OGFuuid_t(&scene->objects, OBJECTIVES_QUEST);
    bool active = scene->quests->on_click;
    sfIntRect rect = object_get_rect(objective);

    if (active && rect.height < 110)
        object_set_rect(objective, (sfIntRect){
            0, 0, rect.width, rect.height + speed});
    else if (!active && rect.height > 0)
        object_set_rect(objective, (sfIntRect){
            0, 0, rect.width, rect.height - speed});
    if (rect.height >= 110 && scene->quests->on_click)
        object_set_rect(objective, (sfIntRect){0, 0, 224, 110});
    if (rect.height <= 5 && !scene->quests->on_click)
        object_set_rect(objective, (sfIntRect){0, 0, 224, 0});
    if (!scene->quests->active)
        scene->quests->on_click = false;
    quests_indicator(scene);
}
