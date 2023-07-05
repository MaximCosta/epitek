/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/

#ifndef SPACE_SHIP_H
#define SPACE_SHIP_H

#include "../rpg.h"

typedef struct s_on_spaceship_scene SpaceShip;
typedef struct space_planete_s space_planete_t;
typedef struct space_planet_init_s SpacePlanetInit;
typedef struct all_planet_s all_planet_t;
typedef struct framebuffer framebuffer_t;

enum on_spaceship_objects {
    SPACE,
    TEXT_SELECTOR,
    TARTINE,
    TARTINE2,
    SPACE_CURSOR,
    LESS_SPEED,
    MORE_SPEED,
    STATS_PANEL,
    CURRENT,
    TO_lAND,
};

struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
    sfTexture *tx;
    sfSprite *sp;
};
struct s_on_spaceship_scene {
    framebuffer_t *bufsc;
    list_t *objects;
    sfColor opacity;
    bool transition;
    float speed;
    float dpl;
    float dpr;
    float ratio;
    bool press;
    int n_stats;
    char *new_current;
    bool lock;
    object_t *stats_panel;
    object_t *mouse;
    char *current_planet;
    space_planete_t *planete;
};

struct space_planete_s {
    object_t *object;
    textobject_t *text;
    textobject_t *stats_speed;
    textobject_t *desc;
    textobject_t *difficulty;
    object_t *icon_planet;
    loc_t obj_position;
    loc_t text_position;
    bool lock;
    float speed;
    sfVector2f size;
    bool is_active;
    int id;
    textobject_t *title;
    int (*func)(void *obj);
    space_planete_t *next;
    all_planet_t *info;
};

struct all_planet_s {
    V2F a;
    V2F b;
    int dist;
    float cs[2];
    float prog;
    float speed;
};
struct space_planet_init_s {
    uuid_t uuid;
    loc_t obj_pos;
    loc_t text_pos;
    bool lock;
    float id;
    float speed;
    const char *name;
    char *text;
    char *title;
    float idd;
    int text_size;
    char *difficulty;
    sfFont *font;
    int (*func)(void *obj);
    const char *desc;
};

void on_spaceship_render(void *scene);

void on_spaceship_event(void *scene, sfEvent *event);

void *on_spaceship_create(void);

void create_planete(SpaceShip *scene_menu, SpacePlanetInit init);

void event_planete(SpaceShip *scene_menu);

sfColor rgba(sfUint8 r, sfUint8 g, sfUint8 b, sfUint8 a);

void put_pixel(framebuffer_t *buffer, int x, int y, sfColor color);

void reduce_pixel(framebuffer_t *bufsc);

void add_gui_space(SpaceShip *scene);

void update_stats_panel(SpaceShip *scene);

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
#endif // SPACE_SHIP_H
