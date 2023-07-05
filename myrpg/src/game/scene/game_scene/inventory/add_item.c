/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** add_item.c
*/

#include "../../../../../include/game/rpg.h"

char *find_name(char *filepath)
{
    char *buffer = NULL;
    char *name = NULL;
    int size = 0;

    scan(filepath, &buffer);
    for (; buffer[size] != '\n'; size++);
    name = malloc(sizeof(char) * (size + 1));
    name[size] = '\0';
    for (int i = 0; i != size; i++)
        name[i] = buffer[i];
    return name;
}

char *find_description(char *filepath)
{
    char *buffer = NULL;
    char *description = NULL;
    int size = 0;
    int i = 0;

    scan(filepath, &buffer);
    for (; buffer[i] != '\n'; i++);
    i++;
    for (; buffer[size + i] != '\0'; size++);
    description = malloc(sizeof(char) * (size + 1));
    description[size] = '\0';
    for (int j = 0; j != size; j++)
        description[j] = buffer[i + j];
    return description;
}

bool find_item(game *scene, char *title)
{
    int i = 0;

    for (; i != 32; i++) {
        if (scene->cases[i].info.name == NULL || scene->cases[i].item == NULL)
            continue;
        if (equal(title, scene->cases[i].info.name))
            return true;
    }
    for (i = 0; i != 4; i++) {
        if (scene->equiped[i].info.name == NULL ||
        scene->equiped[i].item == NULL)
            continue;
        if (equal(title, scene->equiped[i].info.name))
            return true;
    }
    return false;
}

void add_item(game *scene, char *file_path, int id, char const **images)
{
    char *filepath = my_strcat("data/items/", file_path);
    char *name = my_strdup(find_name(filepath));
    char *description = find_description(filepath);

    for (int i = 0; i != 32; i++) {
        if (scene->cases[i].item != NULL)
            continue;
        scene->cases[i].item = object_create_from_image(id, (loc_t){0, 0},
        images[0]);
        object_set_render_priority(scene->cases[i].item, 200);
        scene->cases[i].info.name = my_strdup(name);
        scene->cases[i].info.description = my_strdup(description);
        scene->cases[i].selected = false;
        scene->cases[i].info.name_text = NULL;
        scene->cases[i].info.filepath = my_strdup(file_path);
        scene->cases[i].info.image_item = my_strdup((char *)images[0]);
        scene->cases[i].info.image_flitem = my_strdup((char *)images[1]);
        object_set_rect(scene->cases[i].box, (sfIntRect){0, 0, 48, 48});
        object_set_origin(scene->cases[i].item, (sfVector2f){24, 24});
        scene_add_object(&scene->objects, scene->cases[i].item);
        return;
    }
}
