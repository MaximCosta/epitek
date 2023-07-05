/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../../include/engine/engine.h"

bool elapsed_time_microseconds(float microseconds,
float *time, float *save)
{
    sfTime convert = sfClock_getElapsedTime(ENGINE->clock);

    if (*time == 0) {
        *save = convert.microseconds;
        *time = 1;
    } else {
        *time += convert.microseconds - *save;
        *save = convert.microseconds;
    }
    if (*time >= microseconds) {
        *time = 0;
        return true;
    }
    return false;
}

bool elapsed_time_milliseconds(float milliseconds,
float *time, float *save)
{
    sfTime convert = sfClock_getElapsedTime(ENGINE->clock);

    if (*time == 0) {
        *save = convert.microseconds;
        *time = 1;
    } else {
        *time += convert.microseconds - *save;
        *save = convert.microseconds;
    }
    if (*time / 1000 >= milliseconds) {
        *time = 0;
        return true;
    }
    return false;
}

void get_elapsed_time(float *time, float *save)
{
    sfTime convert = sfClock_getElapsedTime(ENGINE->clock);

    if (*time == 0) {
        *save = convert.microseconds;
        *time = 0.0000001;
    } else {
        *time = convert.microseconds - *save;
        *save = convert.microseconds;
    }
}
