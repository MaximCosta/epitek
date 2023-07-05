/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/

#include "../../../../include/game/rpg.h"

static const char *SWITCH_BACKGROUND_S =
    "./assets/switch_scene/Background.png";
static const char *SWITCH_CURSOR_S = "./assets/main/cursor.png";

void move_rect(SwitchScene *scene);

char **add_tips(void);

void on_switch_scene_render(void *scene)
{
    SwitchScene *switch_scene = (SwitchScene *) scene;
    object_t *cursor =
        object_get_from_uuid(&switch_scene->objects, SWITCH_CURSOR);
    static DeltaTime switch_s = (DeltaTime){.saved = 0.00, .time = 0.00};

    object_set_rotation(
        cursor, object_get_rotation(cursor) + (0.0001 * ENGINE->delta_time));
    move_rect(switch_scene);
    if (elapsed_time_milliseconds(5000, &switch_s.time, &switch_s.saved))
        scene_change(GAME);
    scene_render(switch_scene->objects);
}

void on_switch_scene_event(void *scene, sfEvent *event)
{
    SwitchScene *switch_scene = (SwitchScene *) scene;

    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        scene_change(SHELL);
    if (event->type == sfEvtMouseButtonPressed)
        switch_scene->mouse_press = true;
    if (event->type == sfEvtMouseButtonReleased)
        switch_scene->mouse_press = false;
    scene_handle_events(switch_scene->objects, event);
}

void *on_switch_scene_create(void)
{
    SwitchScene *switch_scene = malloc(sizeof(SwitchScene));

    switch_scene->objects = 0;
    switch_scene->mouse_press = false;
    switch_scene->tips = add_tips();
    scene_add_object(&switch_scene->objects,
        object_create_from_image(
            SWITCH_BACKGROUND, (loc_t){0, 0}, SWITCH_BACKGROUND_S));
    scene_add_object(&switch_scene->objects,
        object_create_from_image(
            SWITCH_CURSOR, (loc_t){1860, 1020}, SWITCH_CURSOR_S));
    scene_add_text(&switch_scene->objects,
        textobject_create(TIPS, (loc_t){78, 995}, switch_scene->tips[8]));
    object_set_rect(
        object_get_from_uuid(&switch_scene->objects, SWITCH_CURSOR),
        (sfIntRect){32, 0, 48, 48});
    object_set_centered_origin(
        object_get_from_uuid(&switch_scene->objects, SWITCH_CURSOR));
    return switch_scene;
}
