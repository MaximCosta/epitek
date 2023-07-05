/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/

#include "../../../../include/game/rpg.h"

static const char *BACKGROUND_S = "./assets/main/FirstGui.png";
static const char *LOGO_S = "./assets/main/logo.png";
static const char *BUTTON_SETTINGS_S = "./assets/main/button_settings.png";
static const char *BUTTON_MUSIC_S = "./assets/main/button_music.png";
static const char *BUTTON_SOUND_S = "./assets/main/button_sound.png";
static const char *ROPE_SMALL_S = "./assets/main/rope_small.png";
static const char *GAME_LOGO_S = "./assets/main/GameLogo.png";
static const char *PARTICLES_S = "./assets/main/Particles.png";
static const char *BLACKSCREEN_S = "./assets/main/BlackTransition.png";

void game_logo_animation(main_scene_t *main_scene);

void create_cursor(main_scene_t *main_scene);

void particles_animation(main_scene_t *main_scene);

void transition_animation(main_scene_t *main_scene);

void create_main_object(main_scene_t *main_scene);

void on_mainscene_render(void *scene)
{
    main_scene_t *main_scene = (main_scene_t *) scene;
    object_t *cursor = GET_OBJ(&main_scene->objects, CURSOR);

    game_logo_animation(scene);
    follow_mouse(cursor);
    particles_animation(main_scene);
    transition_animation(main_scene);
    scene_render(main_scene->objects);
}

void on_mainscene_event(void *scene, sfEvent *event)
{
    main_scene_t *main_scene = (main_scene_t *) scene;
    object_t *black_screen = NULL;

    if (sfMouse_isButtonPressed(sfMouseLeft) ||
    event->type == sfEvtKeyPressed && !main_scene->transition) {
        scene_add_object(&main_scene->objects,
        object_create_from_image(BLACKSCREEN, (loc_t){0, 0},
        BLACKSCREEN_S));
        black_screen = GET_OBJ(&main_scene->objects, BLACKSCREEN);
        sfSprite_setColor(black_screen->sprite, main_scene->opacity);
        main_scene->transition = true;
    }
    scene_handle_events(main_scene->objects, event);
}

void *on_mainscene_create(void)
{
    main_scene_t *main_scene = malloc(sizeof(main_scene_t));
    static bool animation = true;


    if (animation) {
        !animation;
        scene_change(LOAD_MENU);
    }
    main_scene->opacity = sfColor_fromRGBA(255, 255, 255, 0);
    main_scene->transition = false;
    main_scene->objects = 0;
    create_main_object(main_scene);
    create_cursor(main_scene);
    return main_scene;
}
