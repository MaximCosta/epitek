/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/

#include "../../../../include/game/rpg.h"

static const char *RED = "./assets/runner/red.png";
static const char *BLUE = "./assets/runner/blue.png";
static const char *BUTTER = "./assets/runner/butter.png";
static const char *KITCHEN = "./assets/runner/kitchen.jpg";
static const char *R_TARTINE = "./assets/runner/tartine.png";
static const char *R_TARTINEB = "./assets/runner/tartineb.png";
static const char *SOUND_BUTTER = "./assets/runner/squish.ogg";
static const char *SOUND_BITE = "./assets/runner/bite.ogg";
static const char *BOY = "./assets/runner/boy.png";
static const char *BOY2 = "./assets/runner/boy2.png";
static const char *DEAD_ROBLOX_INSANE = "./assets/runner/dead.ogg";
static const char *HEART = "./assets/runner/heart.png";
static const char *FONT = "./assets/runner/font.ttf";

// void my_click(object_t *object)
// {
//     runner_t *runner = scene_get(RUNNER);

//     sfSound_play(runner->sound);
//     runner->tartines[object->uuid]->clicked = 1;
//     object->on_click = NULL;
//     object_set_texture(object, sfTexture_createFromFile(R_TARTINEB, NULL));
// }

void on_runner_render(void *scene)
{
    runner_t *runner = (runner_t *) scene;

    object_set_position(runner->mouse,
    (sfVector2f){sfMouse_getPositionRenderWindow(ENGINE->window).x,
                sfMouse_getPositionRenderWindow(ENGINE->window).y});
    switch (runner->state) {
        case 0:
            runner_do_menu(runner);
            scene_render(runner->menu->obj);
            break;
        case 1:
            runner_do_game(runner->game);
            scene_render(runner->game->obj);
            break;
        case 2:
            runner_do_game_o(runner);
            scene_render(runner->game_o->obj);
            break;
    }
    scene_render(runner->objects);
}

void on_runner_event(void *scene, sfEvent *event)
{
    runner_t *runner = (runner_t *) scene;

    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        if (runner->state == 0)
            return scene_change(SHELL);
    }
    switch (runner->state) {
        case 0:
            scene_handle_events(runner->menu->obj, event);
            break;
        case 1:
            scene_handle_events(runner->game->obj, event);
            break;
        case 2:
            scene_handle_events(runner->game_o->obj, event);
            break;
    }
}

void *on_runner_create(void)
{

    runner_t *runner = my_calloc(sizeof(runner_t));

    runner->menu = my_calloc(sizeof(runner_menu_t));
    runner->game = my_calloc(sizeof(runner_game_t));
    runner->game_o = my_calloc(sizeof(runner_game_o_t));
    runner->font = sfFont_createFromFile(FONT);

    runner_menu_create(runner);
    runner_game_create(runner);
    runner_game_o_create(runner);
    runner->mouse = object_create_from_image(0, (loc_t){0, 0}, BUTTER);
    object_set_centered_origin(runner->mouse);
    object_set_render_priority(runner->mouse, 99);
    scene_add_object(&runner->objects, runner->mouse);
    return runner;
}
