/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** player_death.c
*/

#include "../../../../../include/game/rpg.h"

void game_destroyed_next(game *scene);

bool find_item_opt(game *scene, char *title, int opt)
{
    int i = 0;

    for (; i != 32 && (opt == 1 || opt == 3); i++) {
        if (scene->cases[i].info.name == NULL || scene->cases[i].item == NULL)
            continue;
        if (equal(title, scene->cases[i].info.name))
            return true;
    }
    for (i = 0; i != 4 && (opt == 2 || opt == 3); i++) {
        if (scene->equiped[i].info.name == NULL ||
        scene->equiped[i].item == NULL)
            continue;
        if (equal(title, scene->equiped[i].info.name))
            return true;
    }
    return false;
}

inventory_t *get_item(game *scene, char *title, int opt)
{
    int i = 0;

    for (; i != 32 && (opt == 1 || opt == 3); i++) {
        if (scene->cases[i].info.name == NULL || scene->cases[i].item == NULL)
            continue;
        if (equal(title, scene->cases[i].info.name))
            return &scene->cases[i];
    }
    for (i = 0; i != 4 && (opt == 2 || opt == 3); i++) {
        if (scene->equiped[i].info.name == NULL ||
        scene->equiped[i].item == NULL)
            continue;
        if (equal(title, scene->equiped[i].info.name))
            return &scene->equiped[i];
    }
    return NULL;
}

void destroy_game(game *scene)
{
    scene->toolbar->pv = 100;
    scene->player->pv_max = 100;

    for (int i = 0; i != 32; i++) {
        if (scene->cases[i].item != NULL) {
            scene_remove_object(&scene->objects, scene->cases[i].item);
            scene->cases[i].item = NULL;
        }
        if (i < 5 && scene->equiped[i].item != NULL) {
            scene_remove_object(&scene->objects, scene->equiped[i].item);
            scene->equiped[i].item = NULL;
        }
    }
    game_destroyed_next(scene);
}

void death_animation(game *scene)
{
    static DeltaTime delta = {.time = 0.00, .saved = 0.00};
    object_t *player = OGFuuid_t(&scene->objects, PLAYER);

    if (object_get_rect(player).top >= 768) {
        object_set_rect(player, (sfIntRect){640, 0, 128, 64});
        destroy_game(scene);
        scene_change(MENU);
    }
    if (elapsed_time_milliseconds(125, &delta.time, &delta.saved))
        object_set_rect(player, (sfIntRect){640,
        object_get_rect(player).top + 64, 128, 64});
}

void player_death(game *scene)
{
    inventory_t *get = NULL;

    if (find_item_opt(scene, "RESURRECTION", 2)) {
        scene->toolbar->pv += 75;
        get = get_item(scene, "RESURRECTION", 2);
        scene_remove_object(&scene->objects, get->item);
        get->item = NULL;
        return;
    }
    death_animation(scene);
}
