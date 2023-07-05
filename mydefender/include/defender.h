/*
** EPITECH PROJECT, 2022
** mydefender [WSL: Ubuntu]
** File description:
** defender
*/

#ifndef DEFENDER_H_
    #define DEFENDER_H_
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <fcntl.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include "my.h"
    #define MENU   0
    #define MANI   1
    #define PLAY   2
    #define PANI   3
    #define PAUSE  4
    #define INFO   5
    #define EXIT   6
    #define FMENU  4
    #define FPAUSE 8
    #define FILE   12
typedef struct mobs_s {
    int hp;
    int pw;
    int sp;
    int msp;
    int x;
    int y;
} mobs_t;
typedef struct tower_s {
    sfVector2i cas;
    sfIntRect clvl;
    sfIntRect cor;
    sfVector2f c;
    int dir;
    int lvl;
} tower_t;
typedef struct asset_s {
    sfTexture *ttx;
    sfTexture *tx;
    sfSprite *tsp;
    sfSprite *sp;
    sfIntRect rc;
} asset_t;
typedef struct menu_s {
    sfVector2f *pos;
    sfTexture **tx;
    sfTexture *mtx;
    sfTexture *itx;
    sfVector2i mc;
    sfSprite **sp;
    sfSprite *msp;
    sfSprite *isp;
    sfIntRect rc;
    sfFont *font;
    sfText *text;
    int choice;
    int *np;
} menu_t;
typedef struct game_s {
    sfMusic *mu_upgrade;
    sfRenderWindow *wd;
    sfMusic *mu_craft;
    sfMusic *mu_loop;
    tower_t **towers;
    asset_t *asset;
    sfClock *clock;
    sfTexture *btx;
    sfClock *time;
    sfSprite *bsp;
    mobs_t **mobs;
    bool is_press;
    int **price;
    float delta;
    menu_t *mn;
    int **maps;
    int mtower;
    int ctower;
    int score;
    int money;
    int state;
    int tower;
    int cell;
    int wx;
    int wy;
    int sx;
    int sy;
    int lw;
    int lh;
} game_t;
void destroy_all2(game_t *game);
void destroy_all(game_t *game);
game_t *init_gm(game_t *game, int wx, int wy);
void init_all(game_t *game);
void init_menu(game_t *game);
void init_play(game_t *game);
void init_price(game_t *game);
void init_next(game_t *game, int wx, int wy);
sfRenderWindow *gw(sfVideoMode m, char *str);
void load_map_v2(game_t *game, char *f, int e1, int e2);
void load_map(game_t *game, const char *filename);
void print_map(game_t *game);
char *concat(char *str1, char *str2);
sfText *get_text(sfVector2f pos, const char *str, const int sz, sfFont *ft);
sfVector2f gp(const int x, const int y);
sfBool key_press(sfKeyCode key, sfEvent event);
float asSec(const sfClock *clock);
void print_menu(game_t *game);
void get_menu_event(game_t *game);
void set_animation_menu(game_t *game);
void get_towopen(game_t *game);
int get_tower(game_t *game);
void get_towclose(game_t *game);
void print_mtower(game_t *game);
int check_in(game_t *game, sfVector2i p);
int get_tower_lvl(game_t *game, sfVector2i p);
void set_tower_lvl(game_t *game, sfVector2i p);
void init_tower(game_t *game, int choice);
void print_tower(game_t *game);
void print_info(game_t *game);
void get_info_event(game_t *game);
void print_pause(game_t *game);
void get_pause_event(game_t *game);
void switch_scene(game_t *game);
void update_score(game_t *game);
void print_score(game_t *game);
void print_money(game_t *game);
void apply_level(tower_t *tower, game_t *game);
void init_music(game_t *game);
void play_music(game_t *game);
#endif /* !DEFENDER_H_ */
