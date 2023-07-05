/*
** EPITECH PROJECT, 2021
** Day08
** File description:
** Task01 - MY_STRDUP
*/
#include "../../../include/engine/location/location.h"

loc_t  location_create(float x, float y)
{
   loc_t  location = {0};

    location.x = x;
    location.y = y;
    return location;
}
