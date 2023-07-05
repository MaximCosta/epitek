/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** add_boxes.c
*/

#include "../../../../../include/game/rpg.h"

static const char *EQUIPED_S = "./assets/GameScene/inventory/equiped.png";

void set_box(game *scene, inventory_t *invent,loc_t pos);

void add_boxes(game *scene)
{
   loc_t pos = {0, 0};
    scene->cases = malloc(sizeof(inventory_t) * 33);

    for (int i = 0; i != 32; i++) {
        set_box(scene, &scene->cases[i], pos);
        object_set_rect(scene->cases[i].box, (sfIntRect){0, 0, 100, 100});
        scene_add_object(&scene->objects, scene->cases[i].box);
        object_set_render_priority(scene->cases[i].box, 111);
        if (scene->cases[i].item != NULL)
            scene_add_object(&scene->objects, scene->cases[i].item);
    }
}

void add_equiped(game *scene)
{
    scene->equiped = malloc(sizeof(inventory_t) * 5);

    for (int i = 0; i != 5; i++) {
        scene->equiped[i].box =
            object_create_from_image(EQUIPED, (loc_t){0, 0}, EQUIPED_S);
        scene->equiped[i].item = NULL;
        scene->equiped[i].info.name = my_strdup("NONE");
        scene->equiped[i].info.description = my_strdup("NONE");
        scene->equiped[i].info.name_text =
            textobject_create(EQUIPED_NAME, (loc_t){0, 0}, "NONE");
        scene->equiped[i].selected = false;
        object_set_rect(scene->equiped[i].box, (sfIntRect){0, 0, 226, 89});
        scene_add_object(&scene->objects, scene->equiped[i].box);
        scene_add_text(&scene->objects, scene->equiped[i].info.name_text);
        object_set_render_priority(scene->equiped[i].box, 110);
        object_set_render_priority(
            scene->equiped[i].info.name_text->object, 111);
    }
}
