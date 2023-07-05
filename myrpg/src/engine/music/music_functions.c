/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"

void music_set_repeated(music_t *music, bool repeated)
{
    sfMusic_setLoop(music->sf_music, repeated);
}
