/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** add_object.c
*/

#include "../../../../../include/game/rpg.h"

static const char *MAP_S = "./assets/GameScene/map/map_1.png";
static const char *MAP_BACK_S = "./assets/GameScene/map/map_2.png";
static const char *PLAYER_S = "./assets/GameScene/player/player.png";
static const char *INVENTORY_S = "./assets/GameScene/inventory/Inventory.png";
static const char *CASE_S = "./assets/GameScene/inventory/case.png";
static const char *BLACKSCREEN_GAME_S = "./assets/main/BlackTransition.png";
static const char *CURSOR_GAME_S = "./assets/main/cursor.png";
static const char *INFO_S = "./assets/GameScene/inventory/info.png";

void add_boxes(game *scene);

void add_text(game *scene);

void add_equiped(game *scene);

void add_gui(game *scene);

void add_trader(game *scene);

void add_player(game *scene)
{
    scene_add_object(&scene->objects, object_create_from_image(
        PLAYER, (loc_t){960, 540}, PLAYER_S));
    object_set_rect(object_get_from_uuid(&scene->objects, PLAYER),
        (sfIntRect){0, 0, 128, 64});
    object_set_scale(object_get_from_uuid(&scene->objects, PLAYER),
    (sfVector2f){2, 2});
    object_set_origin(object_get_from_uuid(&scene->objects, PLAYER),
    (sfVector2f){64, 32});
    object_set_render_priority(object_get_from_uuid(&scene->objects, PLAYER),
    1);
    object_set_centered_origin(OGFuuid_t(&scene->objects, PLAYER));
}

void set_box(game *scene, inventory_t *invent,loc_t pos)
{
    invent->box = object_create_from_image(CASE, pos, CASE_S);
    invent->item = NULL;
    invent->info.name = my_strdup("NONE");
    invent->info.description = my_strdup("NONE");
    invent->selected = false;
    invent->info.name_text = NULL;
}

void add_inventory(game *scene)
{
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);
    object_t *inventory;

    scene_add_object(&scene->objects, object_create_from_image(
        INVENTORY, (loc_t){300, 500}, INVENTORY_S));
    object_set_rect(object_get_from_uuid(&scene->objects, INVENTORY),
        (sfIntRect){0, 0, 1300, 600});
    add_equiped(scene);
    add_boxes(scene);
    scene_add_object(&scene->objects, object_create_from_image(
        INFO, (loc_t){0, 0}, INFO_S));
    object_set_visible(object_get_from_uuid(&scene->objects, INFO), false);
    object_set_centered_origin(object_get_from_uuid(&scene->objects, INFO));
    object_set_centered_origin(object_get_from_uuid(&scene->objects,
    INVENTORY));
    inventory = object_get_from_uuid(&scene->objects, INVENTORY);
    object_set_render_priority(inventory, 109);
    object_set_render_priority(object_get_from_uuid(&scene->objects, INFO),
    210);
    object_set_position(inventory, (sfVector2f){960, 540});
}

void add_cursor(game *scene)
{
    object_t *cursor = malloc(sizeof(object_t));

    scene_add_object(&scene->objects, object_create_from_image(
        CURSOR_GAME, (loc_t){0, 0}, CURSOR_GAME_S
    ));
    cursor = object_get_from_uuid(&scene->objects, CURSOR_GAME);
    disable_cursor();
    object_set_rect(cursor, (sfIntRect){0, 0, 32, 32});
    object_set_centered_origin(cursor);
    object_set_render_priority(cursor, 1000);
}

void add_object(game *scene)
{
    scene_add_object(&scene->objects, object_create_from_image(
        BACKGROUND_MAP, (loc_t){-540, -960}, MAP_S));
    scene_add_object(&scene->objects, object_create_from_image(
        MAP_BACK, (loc_t){-540, -960}, MAP_BACK_S));
    object_set_render_priority(object_get_from_uuid(&scene->objects,
    MAP_BACK), 2);
    add_player(scene);
    add_inventory(scene);
    add_gui(scene);
    add_cursor(scene);
    add_text(scene);
    add_trader(scene);
}
