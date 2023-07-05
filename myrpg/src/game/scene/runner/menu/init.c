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

static void start_game(object_t *obj)
{
    runner_t *runner = scene_get(RUNNER);

    runner->state = 1;
    runner_init_tartines(runner->game);
}

static void quit(object_t *obj)
{
    runner_t *runner = scene_get(RUNNER);

    scene_change(SHELL);
}

void runner_menu_create(runner_t *runner)
{
    runner_menu_t *menu = runner->menu;
    textobject_t *text = NULL;
    object_t *obj = NULL;

    text = textobject_create(0, (loc_t) {675, 50}, "RPTV Game");
    textobject_set_font(text, runner->font);
    textobject_set_size(text, 110);
    sfText_setColor(text->text, sfColor_fromRGB(177, 2, 196));
    scene_add_text(&menu->obj, text);

    obj = object_create_from_image(69, (loc_t) {820, 365}, BTN);
    obj->on_hover = my_t;
    obj->on_click = start_game;
    scene_add_object(&menu->obj, obj);
    obj = object_create_from_image(0, (loc_t) {0, 0}, KITCHEN);
    object_set_render_priority(obj, -1);
    scene_add_object(&menu->obj, obj);
    text = textobject_create(0, (loc_t) {879, 367}, "Play");
    textobject_set_font(text, runner->font);
    textobject_set_size(text, 85);
    sfText_setColor(text->text, sfColor_fromRGB(206, 198, 207));
    scene_add_text(&menu->obj, text);
    obj = object_create_from_image(70, (loc_t) {820, 565}, BTN);
    obj->on_hover = my_t;
    obj->on_click = quit;
    scene_add_object(&menu->obj, obj);
    obj = object_create_from_image(0, (loc_t) {0, 0}, KITCHEN);
    object_set_render_priority(obj, -1);
    scene_add_object(&menu->obj, obj);
    text = textobject_create(0, (loc_t) {879, 567}, "Quit");
    textobject_set_font(text, runner->font);
    textobject_set_size(text, 85);
    sfText_setColor(text->text, sfColor_fromRGB(206, 198, 207));
    scene_add_text(&menu->obj, text);
}