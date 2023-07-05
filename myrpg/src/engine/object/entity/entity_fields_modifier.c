/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../../include/engine/engine.h"

void entity_set_state(entity_t *entity, entity_state_t state)
{
    entity->state = state;
}

void entity_set_health(entity_t *entity, double health)
{
    entity->health = health;
}

void entity_set_speed(entity_t *entity, float speed)
{
    entity->speed = speed;
}

void entity_set_attack_damage(entity_t *entity, double attack_damage)
{
    entity->attack_damage = attack_damage;
}
