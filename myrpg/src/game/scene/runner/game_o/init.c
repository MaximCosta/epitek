/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** init.c
*/

#include "../../../../../include/game/rpg.h"

static const char *KITCHEN = "./assets/runner/kitchen.jpg";
static const char *BTN = "./assets/runner/5.png";

static void my_t(object_t *obj)
{
    sfSprite_setColor(obj->sprite, sfColor_fromRGBA(200, 200, 200, 250));
}

static void restart(object_t *obj)
{
    runner_t *runner = scene_get(RUNNER);

    runner->state = 1;
    runner_init_tartines(runner->game);
}

static void goto_menu(object_t *obj)
{
    runner_t *runner = scene_get(RUNNER);

    runner->state = 0;
}

static void place_score(runner_game_o_t *menu, int score, sfFont *font)
{
    str_t *str = str_create("Score: ");
    textobject_t *text = NULL;
    sfFloatRect rect = {0, 0, 0, 0};

    str_add_nbr(str, score);
    text = textobject_create(99, (loc_t) {880, 200}, (const char *) str->str);
    textobject_set_font(text, font);
    textobject_set_size(text, 45);
    sfText_setColor(text->text, sfColor_fromRGB(181, 174, 175));
    rect = sfText_getLocalBounds(text->text);
    textobject_set_position(text, (sfVector2f) {1920 / 2 - rect.width / 2,
                                                200});
    scene_add_text(&menu->obj, text);
    str_destroy(str);
}

void runner_game_o_create(runner_t *runner)
{
    runner_game_o_t *menu = runner->game_o;
    object_t *obj = object_create_from_image(0, (loc_t) {0, 0}, KITCHEN);
    textobject_t *text = textobject_create(0, (loc_t) {715, 100}, "GAME OVER");

    object_set_render_priority(obj, -1);
    scene_add_object(&menu->obj, obj);

    textobject_set_font(text, runner->font);
    textobject_set_size(text, 100);
    sfText_setColor(text->text, sfColor_fromRGB(199, 66, 95));
    scene_add_text(&menu->obj, text);
    place_score(menu, runner->game->score, runner->font);

    obj = object_create_from_image(69, (loc_t) {820, 365}, BTN);
    obj->on_hover = my_t;
    obj->on_click = restart;
    scene_add_object(&menu->obj, obj);
    obj = object_create_from_image(0, (loc_t) {0, 0}, KITCHEN);
    object_set_render_priority(obj, -1);
    scene_add_object(&menu->obj, obj);
    text = textobject_create(0, (loc_t) {825, 367}, "Restart");
    textobject_set_font(text, runner->font);
    textobject_set_size(text, 80);
    sfText_setColor(text->text, sfColor_fromRGB(206, 198, 207));
    scene_add_text(&menu->obj, text);
    obj = object_create_from_image(70, (loc_t) {820, 565}, BTN);
    obj->on_hover = my_t;
    obj->on_click = goto_menu;
    scene_add_object(&menu->obj, obj);
    obj = object_create_from_image(0, (loc_t) {0, 0}, KITCHEN);
    object_set_render_priority(obj, -1);
    scene_add_object(&menu->obj, obj);
    text = textobject_create(0, (loc_t) {870, 567}, "Menu");
    textobject_set_font(text, runner->font);
    textobject_set_size(text, 85);
    sfText_setColor(text->text, sfColor_fromRGB(206, 198, 207));
    scene_add_text(&menu->obj, text);
}