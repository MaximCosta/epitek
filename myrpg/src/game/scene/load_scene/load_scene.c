/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** load_scene.c
*/

#include "../../../../include/game/rpg.h"

static const char *LOAD_BACKGROUND_S = "./assets/Load/Animation.png";
static const char *VOICE_OFF_S = "./assets/sounds/Utchiwa.ogg";
static const char *LOAD_BLACKSCREEN_S = "./assets/main/BlackTransition.png";
static const char *SKIP_S = "./assets/Load/Skip.png";

void fade_out(
    LoadScene *load_scene, int path, object_t *load_background, float time);

void create_cursor_load(LoadScene *load_scene);

void skip_animation(LoadScene *load_scene);

void get_path(int path, object_t *load_background, float speed);

void selecte_path(int *path, object_t *load_background, float speed);

void subtitle_animation(LoadScene *load_scene);

void initiate_scene(LoadScene *scene);

void on_loadscene_render(void *scene)
{
    LoadScene *load_scene = (LoadScene *) scene;
    object_t *load_background = GET_OBJ(&load_scene->objects, LOAD_BACKGROUND);
    static int path = 1;
    float speed = 0.00000002;

    music_play(VOICE_OFF);
    if (object_get_rect(load_background).left
        >= object_get_origin_size(load_background).x)
        scene_change(MAIN_SCENE);
    subtitle_animation(load_scene);
    skip_animation(load_scene);
    get_path(path, load_background, speed);
    fade_out(load_scene, path, load_background, ENGINE->delta_time);
    selecte_path(&path, load_background, speed);
    scene_render(load_scene->objects);
}

void on_loadscene_event(void *scene, sfEvent *event)
{
    LoadScene *load_scene = (LoadScene *) scene;

    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfMusic_pause(music_get_from_uuid(VOICE_OFF)->sf_music);
        scene_change(SHELL);
    }
    if (event->type == sfEvtMouseButtonPressed)
        load_scene->mouse_press = true;
    if (event->type == sfEvtMouseButtonReleased)
        load_scene->mouse_press = false;
    scene_handle_events(load_scene->objects, event);
}

void *on_loadscene_create(void)
{
    LoadScene *load_scene = malloc(sizeof(LoadScene));
    load_scene->objects = 0;
    load_scene->delta_time = (DeltaTime) {0, 0};
    object_t *load_background;
    object_t *black_screen;
    sfColor actual = sfColor_fromRGBA(255, 255, 255, 0);

    scene_change(SHELL);
    initiate_scene(load_scene);
    black_screen = GET_OBJ(&load_scene->objects, LOAD_BLACKSCREEN);
    load_background = GET_OBJ(&load_scene->objects, LOAD_BACKGROUND);
    sfSprite_setColor(black_screen->sprite, actual);
    object_set_rect(load_background, (sfIntRect){0, 0, 1920, 1080});
    object_set_origin(load_background, (sfVector2f){960, 540});
    music_register(music_create_from_file(VOICE_OFF, VOICE_OFF_S));
    scene_add_text(&load_scene->objects,
        textobject_create(
            SUBTITLE, (loc_t){130, 900}, load_scene->subtitle[0]));
    create_cursor_load(load_scene);
    return load_scene;
}
