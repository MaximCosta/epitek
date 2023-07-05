/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"

Setting *setting_create(uuid_t uuid, setting_value_t value,
    setting_value_t default_value)
{
    Setting *setting = malloc(sizeof(Setting));

    setting->uuid = uuid;
    setting->value = value;
    setting->default_value = default_value;
    return setting;
}

void setting_register(Setting *setting)
{
    list_insert_first(&ENGINE->settings_manager->settings, setting);
}

Setting *setting_get(uuid_t uuid)
{
    list_t *setting = ENGINE->settings_manager->settings;

    while (setting) {
        if (CAST(Setting *, setting->value)->uuid == uuid)
            return setting->value;
        setting = setting->next;
    }
    return 0;
}

void *setting_get_value(uuid_t uuid)
{
    Setting *setting = setting_get(uuid);

    if (!setting)
        return 0;
    return setting->value;
}

void *setting_get_default_value(uuid_t uuid)
{
    Setting *setting = setting_get(uuid);

    if (!setting)
        return 0;
    return setting->default_value;
}
