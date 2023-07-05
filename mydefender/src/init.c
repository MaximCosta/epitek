/*
** EPITECH PROJECT, 2022
** mydefender [WSL: Ubuntu]
** File description:
** init
*/

#include "defender.h"

game_t *init_gm(game_t *game, int wx, int wy)
{
    game->wd = 0;
    game->wx = wx;
    game->wy = wy;
    game->cell = 40;
    game->delta = 0;
    game->time = 0;
    game->score = 0;
    game->money = 0;
    game->tower = 0;
    game->state = MENU;
    game->towers = NULL;
    game->is_press = 0;
    init_next(game, wx, wy);
    init_price(game);
    return game;
}

void init_texts(game_t *game)
{
    sfVector2f vec = gp(game->wx / 2 - 192, 100);
    sfFloatRect size;

    game->mn->font = sfFont_createFromFile("./assets/fonts/pixelates.ttf");
    game->mn->text = get_text(vec, "MENU", 96, game->mn->font);
    game->bsp = sfSprite_create();
    game->btx = sfTexture_createFromFile("./assets/img/back.png", NULL);
    sfSprite_setTexture(game->bsp, game->btx, sfTrue);
    game->mn->msp = sfSprite_create();
    game->mn->mtx = sfTexture_createFromFile("./assets/img/tower.png", NULL);
    sfSprite_setTexture(game->mn->msp, game->mn->mtx, sfTrue);
    game->mn->isp = sfSprite_create();
    game->mn->itx = sfTexture_createFromFile("./assets/img/price.png", NULL);
    sfSprite_setTexture(game->mn->isp, game->mn->itx, sfTrue);
    size = sfSprite_getGlobalBounds(game->mn->isp);
    vec.x = (game->wx - size.width) / 2;
    vec.y = (game->wy - size.height) / 2;
    sfSprite_setPosition(game->mn->isp, vec);
}

void init_all(game_t *game)
{
    sfVideoMode mode = {game->wx, game->wy, 32};
    sfVector2f vec = {(float) game->cell / 16, (float) game->cell / 16};
    sfVector2f vec1 = {(float) game->cell / 89, (float) game->cell / 89};

    game->wd = gw(mode, "Defender");
    game->time = sfClock_create();
    game->clock = sfClock_create();
    game->asset->sp = sfSprite_create();
    game->asset->rc = (sfIntRect){0, 0, 16, 16};
    game->asset->tx = sfTexture_createFromFile("./assets/img/its.png", NULL);
    sfSprite_setTexture(game->asset->sp, game->asset->tx, sfTrue);
    sfSprite_setScale(game->asset->sp, vec);
    game->asset->tsp = sfSprite_create();
    game->asset->ttx = sfTexture_createFromFile("./assets/img/twrs.png", NULL);
    sfSprite_setTexture(game->asset->tsp, game->asset->ttx, sfTrue);
    sfSprite_setScale(game->asset->tsp, vec1);
    sfRenderWindow_setFramerateLimit(game->wd, 60);
    init_menu(game);
    init_texts(game);
}

void init_text(game_t *game, int i, int ry)
{
    sfVector2f vec = {.25, .25};
    sfVector2f pos = {0, 0};
    sfIntRect size;

    sfSprite_setTexture(game->mn->sp[i], game->mn->tx[i], sfTrue);
    sfSprite_setScale(game->mn->sp[i], vec);
    size = sfSprite_getTextureRect(game->mn->sp[i]);
    pos.x = game->wx / 2 - (size.width * .25) / 2;
    pos.y = game->wy / 2 + ry;
    sfSprite_setPosition(game->mn->sp[i], pos);
}

void init_menu(game_t *game)
{
    char filenames[12][9] = {"pl_1.png", "pl_2.png", "ex_1.png", "ex_2.png",
        "pa_1.png", "pa_2.png", "pa_3.png", "pa_4.png", "pa_5.png", "pa_6.png",
        "pa_7.png", "pa_8.png"};
    char *path;
    int ry = FMENU / 2 * 150 / 2 * -1;

    for (int i = 0; i < FILE; i++) {
        if (i != 0 && i % 2 == 0)
            ry += 150;
        if (i == FMENU)
            ry = FPAUSE / 2 * 150 / 2 * -1;
        game->mn->sp[i] = sfSprite_create();
        path = concat("./assets/img/", filenames[i]);
        game->mn->tx[i] = sfTexture_createFromFile(path, NULL);
        init_text(game, i, ry);
        game->mn->pos[i] = sfSprite_getPosition(game->mn->sp[i]);
        free(path);
    };
}
