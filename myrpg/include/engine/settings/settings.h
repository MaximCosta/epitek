/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef SETTINGS_H
    #define SETTINGS_H

    #include "../engine.h"

typedef struct s_settings_manager settings_manager_t;
typedef struct s_setting Setting;

struct s_settings_manager {

    list_t *settings;

};

struct s_setting {

    uuid_t uuid;
    setting_value_t value;
    setting_value_t default_value;

};

Setting *setting_create(uuid_t uuid, setting_value_t value,
                        setting_value_t default_value);

void setting_register(Setting *setting);

Setting *setting_get(uuid_t uuid);

void *setting_get_value(uuid_t uuid);

void *setting_get_default_value(uuid_t uuid);

void setting_set(uuid_t uuid, setting_value_t value);

#endif //SETTINGS_H
