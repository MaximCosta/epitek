/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef ENTITY_H
    #define ENTITY_H

    #include "../../engine.h"

typedef struct s_entity entity_t;
typedef enum entity_state entity_state_t;

enum entity_state {

    IDLE,
    WALKING,
    ATTACKING,

};

struct s_entity {

    object_t *object;
    entity_state_t state;
    double health;
    float speed;
    double attack_damage;

};

entity_t *entity_create(list_t *objects, list_t *entities, path_t texture_path);

void entity_set_state(entity_t *entity, entity_state_t state);

void entity_set_health(entity_t *entity, double health);

void entity_set_speed(entity_t *entity, float speed);

void entity_set_attack_damage(entity_t *entity, double attack_damage);

#endif //ENTITY_H
