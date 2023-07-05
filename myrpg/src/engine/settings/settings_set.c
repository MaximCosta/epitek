/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"

void setting_set(uuid_t uuid, setting_value_t value)
{
    Setting *setting = setting_get(uuid);

    if (!setting)
        return;
    setting->value = value;
}
