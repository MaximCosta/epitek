/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef MUSIC_H
    #define MUSIC_H

    #include "../engine.h"

typedef struct s_music_manager music_manager_t;
typedef struct s_music music_t;

struct s_music_manager {

    list_t *musics;

};

struct s_music {

    uuid_t uuid;
    sfMusic *sf_music;

};

music_t *music_create_from_file(uuid_t uuid, path_t path);

void music_register(music_t *music);

music_t *music_get_from_uuid(uuid_t uuid);

void music_play(uuid_t uuid);

void music_pause(uuid_t uuid);

void music_set_repeated(music_t *music, bool repeated);

#endif //MUSIC_H
