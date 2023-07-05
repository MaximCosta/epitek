/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"

music_t *music_create_from_file(uuid_t uuid, path_t path)
{
    music_t *music = malloc(sizeof(music_t));

    music->uuid = uuid;
    music->sf_music = sfMusic_createFromFile(path);
    return music;
}

void music_register(music_t *music)
{
    list_insert_first(&ENGINE->music_manager->musics, music);
}

music_t *music_get_from_uuid(uuid_t uuid)
{
    list_t *music = ENGINE->music_manager->musics;

    while (music) {
        if (((music_t *)music->value)->uuid == uuid)
            return music->value;
        music = music->next;
    }
    return 0;
}

void music_play(uuid_t uuid)
{
    if (sfMusic_getStatus(music_get_from_uuid(uuid)->sf_music) != sfPlaying)
        sfMusic_play(music_get_from_uuid(uuid)->sf_music);
}

void music_pause(uuid_t uuid)
{
    sfMusic_pause(music_get_from_uuid(uuid)->sf_music);
}
