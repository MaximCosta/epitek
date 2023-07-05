/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef GUI_H
    #define GUI_H

    #include "../engine.h"

typedef struct s_gui_manager gui_manager_t;
typedef struct s_gui Gui;

struct s_gui_manager {

    list_t *guis;
    Gui *current_gui;

};

struct s_gui {

    uuid_t uuid;
    object_t *gui_object;
    list_t *objects;

};

void gui_open(uuid_t uuid);

void gui_close(void);

Gui *gui_create(uuid_t uuid, object_t *gui_object);

void gui_register(Gui *gui);

void gui_render(Gui *gui);

bool gui_is_open(uuid_t uuid);

void gui_add_object(Gui *gui, object_t *object);

void gui_add_text(Gui *gui, textobject_t *object);

Gui *gui_get_from_uuid(uuid_t uuid);

#endif //OBJECT_H
