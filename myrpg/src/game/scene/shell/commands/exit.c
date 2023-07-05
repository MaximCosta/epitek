/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** exit.c
*/

#include "../../../../../include/game/rpg.h"

void destroy_music(void)
{
    runner_game_t *runner = ((runner_t *) scene_get(RUNNER))->game;

    sfSound_destroy(runner->sound);
    sfSoundBuffer_destroy(runner->sbuffer);
    sfSound_destroy(runner->sbite);
    sfSoundBuffer_destroy(runner->sbuffer_bite);
    sfSound_destroy(runner->sdead);
    sfSoundBuffer_destroy(runner->sbuffer_dead);
}

void command_exit(shell_t *shell, char **args)
{
    sfMusic_destroy(music_get_from_uuid(VOICE_OFF)->sf_music);
    sfSound_destroy(shell->sound);
    sfSoundBuffer_destroy(shell->sound_buffer);
    destroy_music();
    sfRenderWindow_close(ENGINE->window);
}