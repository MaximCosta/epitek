/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef OBJECT_H
    #define OBJECT_H
    #include "../engine.h"

typedef struct s_objectany objectany_t;
typedef struct s_object object_t;
typedef struct s_textobject textobject_t;
typedef enum object_type object_type_t;
typedef struct s_move_animation move_animation_t;
typedef struct s_texture_animation texture_animation_t;
typedef struct s_animation animation_t;
typedef enum animation_type animationtype_t;

#define GET_OBJ(LIST, X_uuid_t) object_get_from_uuid(LIST, X_uuid_t);

enum object_type {

    OBJECT,
    ENTITY,
    TEXT

};

struct s_objectany {
    object_type_t type;
    void *object;
};

struct s_animation {
    animationtype_t *animation_type;
    void *animation;
};

struct s_textobject {
    object_t *object;
    sfText *text;
};

struct s_object {
    uuid_t uuid;
    short render_priority;
    loc_t location;
    sfSprite *sprite;
    list_t *animations;
    bool visible;
    bool hovered;
    void (*on_hover)(object_t *object);
    void (*on_unhover)(object_t *object);
    void (*on_click)(object_t *object);
};

enum animation_type {

    MOVE_ANIMATION,
    TEXTURE_ANIMATION

};

struct s_move_animation {
    int status;
    sfSprite *object;
    float time;
    sfVector2f goal_pos;
    void (*on_finish)(object_t *, move_animation_t *);
};

struct s_texture_animation {
    sfTexture *flip_texture;
    sfTexture *texture;
    Graph *frames;
    Graph *curr_frame;
    float speed;
    sfClock *clock;
    bool loop;
};

object_t *object_create(uuid_t uuid,loc_t location);

object_t *object_create_sprite(uuid_t uuid,loc_t location, sfSprite *sprite);

object_t *object_get_from_any(void *object_any);

object_t *object_create_from_image(uuid_t uuid,loc_t location, path_t path);

object_t *object_get_from_uuid(list_t **objects, uuid_t uuid);

void object_set_origin(object_t *object, sfVector2f origin);

void object_set_visible(object_t *object, bool visible);

bool object_is_visible(object_t *object);

void object_set_hovered(object_t *object, bool hovered);

bool object_is_hovered(object_t *button_image);

void object_set_scale(object_t *object, sfVector2f scale);

void object_set_centered_origin(object_t *object);

void object_set_texture(object_t *object, sfTexture *texture);

bool object_on_hover(object_t *object, void (*on_hover)(object_t *object));

bool object_on_unhover(object_t *object, void (*on_unhover)(object_t *object));

void object_on_click(object_t *object, void (*on_click)(object_t *object));

void object_handle_hover_event(object_t *button);

void object_handle_events(list_t *objects, sfEvent *event);

void object_handle_click_event(object_t *button);

void object_set_render_priority(object_t *object, short priority);

void object_sort(list_t **objects);

textobject_t *textobject_create(
    uuid_t uuid,loc_t location, const char *text);

textobject_t *textobject_get_from_uuid(list_t **objects, uuid_t uuid);

void textobject_set_string(textobject_t *object, const char *text);

void textobject_set_font(textobject_t *object, sfFont *font);

void textobject_set_size(textobject_t *object, unsigned int size);

sfVector2f object_get_size(object_t *object);

void object_set_position(object_t *object, sfVector2f location);

sfVector2f object_get_position(object_t *object);

void follow_mouse(object_t *object);

void disable_cursor(void);

void object_set_rect(object_t *object, sfIntRect rect);

void object_set_rectlist(object_t **object, sfIntRect rect, int size);

sfIntRect object_get_rect(object_t *object);

sfVector2f object_get_origin_size(object_t *object);

sfVector2f object_get_scale(object_t *object);

void object_set_rotation(object_t *object, float angle);

float object_get_rotation(object_t *object);

void textobject_set_position(textobject_t *object, sfVector2f pos);

int transaction(int i);

objectany_t *object_get_any_from_object(list_t **object_list, void *object);

sfVector2f textobject_get_position(textobject_t *textobject);

#endif // OBJECT_H
