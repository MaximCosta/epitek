/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** runner.h
*/

/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** shell.h
*/

#ifndef RUNNER_H
    #define RUNNER_H

    #include "../rpg.h"

    #define MAX_TARTINES 10

typedef struct runner_s runner_t;
typedef struct tartine_s tartine_t;

typedef struct runner_menu_s runner_menu_t;
typedef struct runner_game_s runner_game_t;
typedef struct runner_game_o_s runner_game_o_t;

struct runner_s {

    runner_menu_t *menu;
    runner_game_t *game;
    runner_game_o_t *game_o;

    int state;

    list_t *objects;
    sfColor opacity;

    object_t *mouse;

    sfFont *font;

};

struct tartine_s {

    object_t *obj;
    int clicked;
    int set;
    int dir;

};

struct runner_game_o_s {

    list_t *obj;

};

struct runner_game_s {

    list_t *obj;

    object_t *boy;
    object_t *boy2;

    tartine_t *tartines[10];

    sfSoundBuffer *sbuffer;
    sfSound *sound;

    sfSoundBuffer *sbuffer_bite;
    sfSound *sbite;

    sfSoundBuffer *sbuffer_dead;
    sfSound *sdead;

    int life;
    int score;

    textobject_t *score_text;

};

struct runner_menu_s {

    list_t *obj;

};

void on_runner_render(void *scene);

void on_runner_event(void *scene, sfEvent *event);

void *on_runner_create(void);

void init_tartines(runner_t *runner);
void add_tartine(runner_game_t *runner, sfVector2f pos, int dir);
void add_tartine_random(runner_game_t *runner);

void do_tartine(runner_game_t *runner);

void my_click(object_t *object);

int test_colide(object_t *obj, object_t *other);

int random_int(int min, int max);

void add_tartine(runner_game_t *runner, sfVector2f pos, int dir);
void runner_init_tartines(runner_game_t *runner);

void runner_menu_create(runner_t *runner);
void runner_do_menu(runner_t *runner);

void runner_game_create(runner_t *runner);
void runner_do_game(runner_game_t *runner);

void runner_game_o_create(runner_t *runner);
void runner_do_game_o(runner_t *runner);

#endif //RUNNER_H
