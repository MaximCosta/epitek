/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../include/game/rpg.h"

void event_handler(sfEvent *event)
{
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape) {
        if (scene_is_current(MAIN_SCENE))
            scene_change(SHELL);
    }
}

void window_handler(void)
{
    return;
}

void create_scenes(void)
{
    scene_create(
        &on_mainscene_render, &on_mainscene_event, &on_mainscene_create);
    scene_create(
        &on_menuscene_render, &on_menuscene_event, &on_menuscene_create);
    scene_create(
        &on_loadscene_render, &on_loadscene_event, &on_loadscene_create);
    scene_create(&on_switch_scene_render, &on_switch_scene_event,
        &on_switch_scene_create);
    scene_create(&on_game_render, &on_game_event, &on_game_create);
    scene_create(
        &on_spaceship_render, &on_spaceship_event, &on_spaceship_create);
    scene_create(&on_shell_render, &on_shell_event, &on_shell_create);
    scene_create(&on_runner_render, &on_runner_event, &on_runner_create);
}

int main(int argc, char **argv)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(
        mode, "MyDefender", sfDefaultStyle | sfFullscreen, NULL);

    engine_init(window);
    register_settings();
    register_musics();
    sfRenderWindow_setFramerateLimit(window, 60);
    create_scenes();
    engine_start(&window_handler, &event_handler);
    return 1;
}
