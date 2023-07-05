/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef SOUND_H
    #define SOUND_H

    #include "../engine.h"

typedef struct s_sound_manager sound_manager_t;
typedef struct s_sound sound_t;

struct s_sound_manager {

    list_t *sounds;

};

struct s_sound {

    uuid_t uuid;
    sfSound *sf_sound;
    sfSoundBuffer *sf_sound_buffer;

};

sound_t *sound_create_from_file(uuid_t uuid, path_t path);

void sound_register(sound_t *sound);

sound_t *sound_get_from_uuid(uuid_t uuid);

void sound_play(uuid_t uuid);

void sound_pause(uuid_t uuid);

#endif //SOUND_H
