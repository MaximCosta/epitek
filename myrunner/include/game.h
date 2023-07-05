/*
** EPITECH PROJECT, 2021
** test [WSL: Ubuntu]
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_
    #define layers 3
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <ncurses.h>
    #include <unistd.h>
    #include <assert.h>
    #include <string.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <time.h>
    #include <pwd.h>

struct maps_s {
    sfVector2f start;
    int **board;
    float time;
    float m;
    int h;
    int w;
};
struct player_s {
    sfTexture **tx;
    sfSprite **sp;
    float jump;
    float py;
    float px;
    int m;
};
struct death_s {
    sfMusic *music;
    sfBool death;
    sfText *text;
    sfTexture *t;
    sfSprite *s;
    int count;
    int curr;
};
struct score_s {
    sfText *text;
    sfFont *font;
    int score;
};
struct game_s {
    sfRenderWindow *window;
    sfSprite **sp_ground;
    sfSprite **sp_back;
    sfTexture **ground;
    sfTexture **back;
    sfClock *clock;
    sfIntRect *rec;
    sfMusic *music;
    sfEvent event;
    sfBool jumped;
    sfBool rpause;
    sfBool pause;
    float spause;
    float sclock;
    struct player_s *pl;
    struct death_s *dh;
    struct score_s *sc;
};

/* typedef */
typedef struct maps_s maps_t;
typedef struct player_s player_t;
typedef struct death_s death_t;
typedef struct score_s score_t;
typedef struct game_s game_t;

/* init_all.c */
void play_music(game_t *games);
void init_music(game_t *games);
void init_text(game_t *games);
void init_all(game_t *games, maps_t *maps);

/* help.c */
int help(int stat);

/* maps.c */
void init_ground(game_t *games);
void tmp_map_render_2(game_t *games, maps_t *maps, int i, int j);
void tmp_map_render(game_t *games, maps_t *maps);
maps_t *create_map(char const *filename);

/* player_1.c */
void init_player_variables(game_t *games, int nb);
void init_player(game_t *games, maps_t *maps);
void player_render(game_t* games);
void player_controller(game_t *games, maps_t *maps);

/* player_2.c */
void player_jump(game_t *games, maps_t *maps);
void player_rotate(game_t* games);
void player_bounce(game_t* games, maps_t *maps);

/* wallpaper.c */
void get_move(game_t *games);
void reset_pos_back(game_t *games);
void draw_sprites(game_t *games);
void load_wallpaper(const char *filename, game_t *games, int order);
void init_wallpaper(game_t *games);

/* destroy.c */
void destroy_loop(game_t *games, maps_t *maps);
void destroy_all(game_t *games, maps_t *maps);
void free_all(game_t *games, maps_t *maps);

/* main.c */
void game_event(game_t *gm);
void request_pause(game_t *games, maps_t *maps, float clock);
void loop_game(game_t *games, maps_t *maps);

/* write.c */
void init_score(game_t *gm);
void init_writer(game_t *gm);
void write_score(game_t *gm);
void write_text(game_t *gm, const char *str);

/* utils.c */
sfVector2f gp(const int x, const int y);
sfIntRect gt(const int t, const int l, const int w, const int h);
sfText *get_text(sfVector2f pos, const char *str, const int sz, sfFont *ft);
sfBool key_press(sfKeyCode key, game_t *gm);
float asSec(const sfClock *clock);

/* death.c */
void death_init(game_t *gm);
void death_animation(game_t *gm, maps_t *mp);
void show_nb_death(game_t *gm);
void reset_maps(game_t *gm, maps_t *mp);

#endif /* !GAME_H_ */
