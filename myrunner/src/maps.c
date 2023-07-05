/*
** EPITECH PROJECT, 2021
** test [SSH: 192.168.177.128]
** File description:
** maps_render
*/

#include "game.h"
#include "my.h"
#include "my_printf.h"

void init_ground(game_t *gm)
{
    int g[17] = {0, 1, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15, 16, 17, 21, 22, -1};
    char *path;
    char buf[3] = {0};

    gm->sp_ground = malloc(sizeof(sfSprite*) * 22);
    gm->ground = malloc(sizeof(sfTexture*) * 22);
    for (int k = 0; g[k] != -1; k++) {
        path = my_calloc(1UL, 0, 255);
        gm->sp_ground[g[k]] = sfSprite_create();
        my_strcat(path, "./assets/images/connect-ground/ground-1-");
        my_itoa(g[k], buf, 10);
        my_strcat(path, buf);
        my_strcat(path, ".png");
        gm->ground[g[k]] = sfTexture_createFromFile(path, NULL);
        sfSprite_setTexture(gm->sp_ground[g[k]], gm->ground[g[k]], sfTrue);
        free(path);
    }
}

void tmp_map_render_2(game_t *gm, maps_t *mp, int i, int j)
{
    int pos[4][3] = {{i-1, j, 5}, {i, j-1, 1}, {i+1, j, 9}, {i, j+1, 7}};
    int tx = 0;

    if (mp->board[i][j] != 1) return;
    for (int k = 0; k < 4; k++) {
        if ((0 <= pos[k][0] && pos[k][0] < mp->h) &&
            (0 <= pos[k][1] && pos[k][1] < mp->w) &&
            (mp->board[pos[k][0]][pos[k][1]] == 1)) {
            tx += pos[k][2];
        }
    }
    sfSprite_setPosition(gm->sp_ground[tx], gp((j - mp->m) * 40, i * 40));
    sfRenderWindow_drawSprite(gm->window, gm->sp_ground[tx], NULL);
}

void tmp_map_render(game_t *games, maps_t *maps)
{
    for (int i = 0; i < maps->h; i++)
        for (int j = maps->m; j < maps->w; j++)
            tmp_map_render_2(games, maps, i, j);
}

maps_t *create_map(char const *filename)
{
    maps_t *maps = malloc(sizeof(maps_t));
    char *line = malloc(21);
    char *back = line;
    size_t n = 300;
    FILE* file;

    if ((file = fopen(filename, "r")) == NULL) return NULL;
    getline(&line , &n, file);
    maps->h = my_strtol(line, &line);
    maps->w = my_strtol(line, &line);
    getline(&line , &n, file);
    maps->start = gp(my_strtol(line, &line) * 40, my_strtol(line, &line) * 40);
    line = my_realloc(back ,maps->w + 3);
    maps->board = malloc(sizeof(int*) * (maps->h + 1));
    for (int j = 0; getline(&line, &n, file) && j <= maps->h; j++) {
        maps->board[j] = malloc(sizeof(int) * maps->w);
        for (int i = 0; i < maps->w; i++)
            maps->board[j][i] = NUM(line[i]);
    }
    maps->m = 0;
    free(line);
    fclose(file);
    return maps;
}
