/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../../include/game/rpg.h"
#include "string.h"

static void *malloc_val(size_t size, int i)
{
    void *val = malloc(size);

    return my_memcpy(val, &i, size);
}

void register_settings(void)
{
    setting_register(setting_create(MUSIC_SETTING,
        malloc_val(sizeof(int), true),
        malloc_val(sizeof(int), true)
    ));
    setting_register(setting_create(SOUND_SETTING,
        malloc_val(sizeof(int), true),
        malloc_val(sizeof(int), true)
    ));
}
