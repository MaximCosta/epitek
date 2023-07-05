/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/

#include "../../../../include/game/rpg.h"

void create_cursor_m(MenuScene *menu_scene);

void button_settings(MenuScene *scene, object_t *cursor);

void create_object_menu(MenuScene *scene);

void on_hover_rect_tree(object_t *object);

void on_unhover_rect_tree(object_t *object);

void button_event_click(MenuScene *scene, sfEvent *event, bool *press);

void black_transition(MenuScene *scene);

void scene_visibility(MenuScene *scene, bool fade_out);

void black_fade_out(MenuScene *scene, bool *fade_out);

void selected_difficulty(MenuScene *scene, bool *fade_out);

void how_to_play(MenuScene *scene);

void check_visibility(MenuScene *menu_scene)
{
    OGFuuid_t(&menu_scene->objects, HOW_TO_PLAY)->visible = false;
    OGFuuid_t(&menu_scene->objects, HTP_DRAW)->visible = false;
    OGFuuid_t(&menu_scene->objects, FONDU)->visible = false;
    if (OGFuuid_t(&menu_scene->objects, PLAY_BUTTON)->visible)
        return;
    OGFuuid_t(&menu_scene->objects, PLAY_BUTTON)->visible = true;
    OGFuuid_t(&menu_scene->objects, MULTIPLAYER_BUTTON)->visible = true;
    OGFuuid_t(&menu_scene->objects, BACK_TO_MENU)->visible = true;
    OGFuuid_t(&menu_scene->objects, TITLE)->visible = true;
}

void on_menuscene_render(void *scene)
{
    MenuScene *menu_scene = (MenuScene *) scene;
    object_t *cursor = object_get_from_uuid(&menu_scene->objects, CURSOR_M);
    static bool fade_out = false;
    static sfEvent event;

    follow_mouse(cursor);
    if (menu_scene->selected_htp) {
        how_to_play(menu_scene);
        scene_render(menu_scene->objects);
        return;
    }
    check_visibility(menu_scene);
    if (!fade_out)
        button_settings(scene, cursor);
    selected_difficulty(menu_scene, &fade_out);
    black_transition(menu_scene);
    scene_visibility(scene, fade_out);
    black_fade_out(menu_scene, &fade_out);
    scene_render(menu_scene->objects);
}

void on_menuscene_event(void *scene, sfEvent *event)
{
    MenuScene *menu_scene = (MenuScene *) scene;

    if (event->type == sfEvtKeyPressed &&
    event->key.code == sfKeyEscape) {
        if (menu_scene->selected_htp)
            menu_scene->selected_htp = false;
        else
            scene_change(SHELL);
    }
    if (event->type == sfEvtMouseButtonPressed)
        menu_scene->mouse_press = true;
    if (event->type == sfEvtMouseButtonReleased)
        menu_scene->mouse_press = false;
    menu_scene->wheel = event->mouseWheelScroll.delta;
    scene_handle_events(menu_scene->objects, event);
}

void *on_menuscene_create(void)
{
    MenuScene *menu_scene = malloc(sizeof(MenuScene));
    menu_scene->mouse_press = false;

    menu_scene->objects = 0;
    menu_scene->selected = 0;
    menu_scene->slected_difficulty = false;
    menu_scene->reverse = 0;
    menu_scene->wheel = 0;
    menu_scene->selected_htp = false;
    create_object_menu(menu_scene);
    create_cursor_m(menu_scene);
    return menu_scene;
}
