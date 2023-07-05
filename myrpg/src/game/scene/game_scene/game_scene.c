/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/

#include "../../../../include/game/rpg.h"

void add_object(game *scene);

void player_movement(game *scene);

void input(game *scene, sfEvent *event);

void init_var(game *scene);

void player_event(game *scene);

void inventory(game *scene);

void set_difficulty(game *scene);

void add_item(game *scene, char *filepath, int id, char const *image);

void update_gui(game *scene);

void update_creation_enemy(game *scene);

void ia(game *scene);

void flitem_process(game *scene);

void take_item(game *scene);

void add_gui(game *scene);

void update_xp(game *scene);

void auto_inventory_class(game *scene);

void update_mouse(game *scene);

void udpate_player_stats(game *scene);

void update_quests(game *scene);

void update_this_gui(game *scene);

void add_trader(game *scene);

void update_trader(game *scene);

void update_menu(game *scene);

void re_create_game(game *scene);

void on_game_render(void *scene)
{
    game *game_scene = (game *) scene;

    if (game_scene->game_destroyed)
        re_create_game(game_scene);
    set_difficulty(game_scene);
    player_movement(game_scene);
    player_event(game_scene);
    inventory(game_scene);
    update_gui(game_scene);
    auto_inventory_class(game_scene);
    update_xp(game_scene);
    take_item(scene);
    flitem_process(game_scene);
    udpate_player_stats(game_scene);
    update_quests(game_scene);
    update_this_gui(game_scene);
    update_trader(game_scene);
    update_menu(game_scene);
    game_scene->difficulty = 3;
    update_creation_enemy(scene);
    ia(scene);
    update_mouse(game_scene);
    scene_render(game_scene->objects);
}

void on_game_event(void *scene, sfEvent *event)
{
    game *game_scene = (game *) scene;

    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape) {
        if (game_scene->menu->active && !game_scene->menu->edit_key) {
            game_scene->player->PAUSE = false;
            game_scene->menu->active = false;
        } else {
            game_scene->menu->active = true;
            game_scene->player->PAUSE = true;
            game_scene->player->INVENTORY_O = false;
            game_scene->trader->active = false;
            game_scene->player->is_profile_gui_opened = false;
        }
        game_scene->menu->edit_key = false;
    }
    if (event->type == sfEvtMouseButtonPressed)
        game_scene->mouse_press = true;
    if (event->type == sfEvtMouseButtonReleased)
        game_scene->mouse_press = false;
    input(game_scene, event);
    scene_handle_events(game_scene->objects, event);
}

void init_key_input(game *scene)
{
    scene->key_input = malloc(sizeof(input_t));

    scene->key_input->inventory = 0;
    scene->key_input->right = 3;
    scene->key_input->left = 16;
    scene->key_input->up = 25;
    scene->key_input->down = 18;
    scene->key_input->dash = 38;
    scene->key_input->jet_pack = 57;
    scene->key_input->interact = 5;
}

void *on_game_create(void)
{
    game *game_scene = malloc(sizeof(game));
    game_scene->objects = 0;

    init_key_input(game_scene);
    add_object(game_scene);
    init_var(game_scene);
    return game_scene;
}
