/*
** EPITECH PROJECT, 2022
** test [SSH: 192.168.177.128]
** File description:
** wallpaper
*/

#include "game.h"
#include "my.h"
#include "my_printf.h"
#include <math.h>

void load_wallpaper(const char *filename, game_t *games, int order)
{
    int index;

    for (int i = 0; i < 2; i++) {
        index = (2 * order) + i;
        games->sp_back[index] = sfSprite_create();
        games->back[index] = sfTexture_createFromFile(filename, NULL);
        sfSprite_setTexture(games->sp_back[index], games->back[index], sfTrue);
        if (index % 2 == 0)
            sfSprite_setPosition(games->sp_back[index], (sfVector2f){1920, 0});
    }
}

void init_wallpaper(game_t *games)
{
    games->sp_back = malloc(sizeof(sfSprite*) * (2 * layers));
    games->back = malloc(sizeof(sfTexture*) * (2 * layers));
    load_wallpaper("./assets/images/back-1.png", games, 0);
    load_wallpaper("./assets/images/back-2.png", games, 1);
    load_wallpaper("./assets/images/back-3.png", games, 2);
}

void get_move(game_t *games)
{
    float speed = .25;

    for (int i = 0; i < (2 * layers); i++) {
        if (i % 2 == 0) speed *= 2;
        sfSprite_move(games->sp_back[i], (sfVector2f){-speed, 0});
    }
}

void reset_pos_back(game_t *games)
{
    for (int i = 0; i < (2 * layers); i++) {
        if (sfSprite_getPosition(games->sp_back[i]).x <= -1920)
            sfSprite_setPosition(games->sp_back[i], (sfVector2f){1920, 0});
    }
}

void draw_sprites(game_t *games)
{
    for (int i = 0; i < (2 * layers); i++)
        sfRenderWindow_drawSprite(games->window, games->sp_back[i], NULL);
}
