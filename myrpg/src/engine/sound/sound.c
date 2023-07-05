/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"

sound_t *sound_create_from_file(uuid_t uuid, path_t path)
{
    sound_t *sound = malloc(sizeof(sound_t));
    sfSound *sf_sound = sfSound_create();

    sound->uuid = uuid;
    sound->sf_sound = sf_sound;
    sound->sf_sound_buffer = sfSoundBuffer_createFromFile(path);
    sfSound_setBuffer(sf_sound, sound->sf_sound_buffer);
    return sound;
}

void sound_register(sound_t *sound)
{
    list_insert_first(&ENGINE->sound_manager->sounds, sound);
}

sound_t *sound_get_from_uuid(uuid_t uuid)
{
    list_t *sound = ENGINE->sound_manager->sounds;

    while (sound) {
        if (((sound_t *)sound->value)->uuid == uuid)
            return sound->value;
        sound = sound->next;
    }
    return 0;
}

void sound_play(uuid_t uuid)
{
    sfSound_play(sound_get_from_uuid(uuid)->sf_sound);
}

void sound_pause(uuid_t uuid)
{
    sfSound_pause(sound_get_from_uuid(uuid)->sf_sound);
}
