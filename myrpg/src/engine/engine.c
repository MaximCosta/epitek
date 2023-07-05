/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../include/engine/engine.h"

static const char *FONT_S = "./assets/GameScene/fredoka.ttf";

engine_t *get_engine(void)
{
    static engine_t engine = {0};

    return &engine;
}

void engine_init(sfRenderWindow *window)
{
    ENGINE->window = window;
    ENGINE->sound_manager = malloc(sizeof(sound_manager_t));
    ENGINE->sound_manager->sounds = 0;
    ENGINE->music_manager = malloc(sizeof(music_manager_t));
    ENGINE->music_manager->musics = 0;
    ENGINE->settings_manager = malloc(sizeof(settings_manager_t));
    ENGINE->settings_manager->settings = 0;
    ENGINE->gui_manager = malloc(sizeof(gui_manager_t));
    ENGINE->gui_manager->guis = 0;
    ENGINE->gui_manager->current_gui = 0;
    ENGINE->default_font = sfFont_createFromFile(FONT_S);
    scene_manager_init();
    ENGINE->clock = sfClock_create();
}

void engine_start(void (*window_handler)(),
        void (*event_handler)(sfEvent *event))
{
    scene_manager_t *scene_manager = ENGINE->scene_manager;
    float saved = 0.00;
    sfEvent event;

    while (sfRenderWindow_isOpen(ENGINE->window)) {
        while (event_handler &&
            sfRenderWindow_pollEvent(ENGINE->window, &event)) {
            (event_handler)(&event);
            if (scene_get_current())
                scene_manager->handle_event[scene_get_current_index()]
                    (scene_get_current(), &event);
        }
        sfRenderWindow_clear(ENGINE->window, sfBlack);
        (window_handler)();
        if (scene_get_current()) {
            scene_manager->on_render[scene_get_current_index()]
                (scene_get_current());
        }
        sfRenderWindow_display(ENGINE->window);
        get_elapsed_time(&ENGINE->delta_time, &saved);
        if (ENGINE->delta_time < 4200)
            ENGINE->delta_time = 4200;
    }
}
