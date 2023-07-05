/*
** EPITECH PROJECT, 2022
** mydefender [WSL: Ubuntu]
** File description:
** maps
*/

#include "defender.h"

void maps_key(game_t *game, char f, int cor[2], int e[2])
{
    if (f == '.')
        game->maps[cor[0]][cor[1]++] = 0;
    if (f == '#')
        game->maps[cor[0]][cor[1]++] =
            ((rand() % 3 + 5) * 10 + 10) + (rand() % 3);
    if (f == 'X') {
        game->maps[cor[0]][cor[1]++] = 13;
        game->ctower++;
    }
    if (f == 'B')
        game->maps[cor[0]][cor[1]++] = 14;
    if (f == 'E') {
        e[0] = (e[0] + 1) % 4;
        e[1] = (e[1] + (e[0] == 0 ? 1 : 0)) % 5;
        game->maps[cor[0]][cor[1]++] = (e[1] * 100) + (e[0] + 8);
    }
}

void load_map_v2(game_t *game, char *f, int e1, int e2)
{
    int cor[2] = {0, 0};
    int e[2] = {e1, e2};

    game->maps = (int **) my_calloc_2d(sizeof(int *), game->lh + 1);
    game->maps[0] = malloc(sizeof(int) * game->lw);
    for (int i = 0; f[i]; i++) {
        if (f[i] == '\n') {
            game->maps[++cor[0]] = malloc(sizeof(int) * game->lw);
            cor[1] = 0;
            continue;
        }
        maps_key(game, f[i], cor, e);
    }
    free(f);
}

void load_map(game_t *game, const char *filename)
{
    int dp = open(filename, O_RDWR);
    char *f = NULL;
    struct stat st;
    size_t size;

    game->lh = 1;
    game->lw = 0;
    if (dp == -1)
        my_exit(84, "no maps loaded\n");
    stat(filename, &st);
    size = st.st_size;
    f = (char *) my_calloc(1UL, 0, size + 1);
    if (read(dp, f, size) == -1)
        my_exit(84, "error reading\n");
    for (int i = 0; f[i]; f[i++] == '\n' ? game->lh++ : 0) {};
    for (int i = 0; f[i] != '\n' && f[i]; f[i++] ? game->lw++ : 0) {};
    game->ctower = 0;
    close(dp);
    load_map_v2(game, f, -1, 0);
}

void print_map_v2(game_t *game, int y, int r1, int r2)
{
    sfVector2f vec;

    for (int x = 0; x < game->lw; x++) {
        if (game->maps[y][x] == 0)
            continue;
        r1 = game->maps[y][x] / (game->maps[y][x] >= 100 ? 100 : 10) - 1;
        r2 = game->maps[y][x] % (game->maps[y][x] >= 100 ? 100 : 10);
        game->asset->rc = (sfIntRect){r2 * 16, r1 * 16, 16, 16};
        sfSprite_setTextureRect(game->asset->sp, game->asset->rc);
        vec.x = x * game->cell + game->sx;
        vec.y = y * game->cell + game->sy;
        sfSprite_setPosition(game->asset->sp, vec);
        sfRenderWindow_drawSprite(game->wd, game->asset->sp, NULL);
    }
}

void print_map(game_t *game)
{
    for (int y = 0; y < game->lh; y++)
        print_map_v2(game, y, 0, 0);
}
