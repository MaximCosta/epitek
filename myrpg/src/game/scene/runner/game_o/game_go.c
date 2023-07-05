/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** game_go.c
*/

#include "../../../../../include/game/rpg.h"

static void place_score(runner_game_o_t *menu, int score)
{
    str_t *str = str_create("Score: ");
    textobject_t *text = textobject_get_from_uuid(&menu->obj, 99);
    sfFloatRect rect = {0, 0, 0, 0};

    str_add_nbr(str, score);
    textobject_set_string(text, str->str);
    sfText_setColor(text->text, sfColor_fromRGB(181, 174, 175));
    rect = sfText_getLocalBounds(text->text);
    textobject_set_position(text, (sfVector2f) {1920 / 2 - rect.width / 2,
                                                200});
    str_destroy(str);
}

void runner_do_game_o(runner_t *runner)
{
    runner_game_o_t *menu = runner->game_o;
    object_t *obj = object_get_from_uuid(&menu->obj, 69);
    object_t *obj2 = object_get_from_uuid(&menu->obj, 70);

    if (!object_is_hovered(obj))
        sfSprite_setColor(obj->sprite, sfColor_fromRGB(255, 255, 255));
    if (!object_is_hovered(obj2))
        sfSprite_setColor(obj2->sprite, sfColor_fromRGB(255, 255, 255));
    place_score(menu, runner->game->score);
}