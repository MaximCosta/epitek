/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef SCENE_H
    #define SCENE_H

    #include "../engine.h"

typedef struct s_scene_manager scene_manager_t;

struct s_scene_manager {

    void **scenes;
    int current_scene;
    int scene_count;
    void (**on_render)(void *);
    void (**handle_event)(void *, sfEvent *);

};

void scene_create(void (*on_render)(void *),
    void (*handle_event)(void *, sfEvent *event), void *(*on_create)(void));

void *scene_get(int scene);

bool scene_is_current(int scene);

void *scene_get_current();

int scene_get_current_index(void);

void scene_manager_init(void);

void scene_add_object(list_t **object_list, void *object);

void scene_add_entity(list_t **object_list, void *entity);

void scene_add_text(list_t **object_list, void *text);

void scene_render(list_t *objects);

void scene_handle_events(list_t *objects, sfEvent *event);

void scene_change(int scene);

void scene_remove_object(list_t **object_list, void *object);

#endif //SCENE_H
