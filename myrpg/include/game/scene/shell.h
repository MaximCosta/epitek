/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** shell.h
*/

#ifndef SHELL_H
    #define SHELL_H

    #include "../rpg.h"

    // #define GTXT(obj, uuid) textobject_get_by_uuid(obj, uuid)

typedef struct s_on_shell_scene shell_scene_t;
typedef struct shell_s shell_t;
typedef struct shell_char_s shell_char_t;
typedef struct shell_history_s shell_history_t;
typedef struct shell_commands_s shell_commands_t;
typedef struct shell_fix_key_s shell_fix_key_t;

enum on_shell_objects {
    NONE
};

struct s_on_shell_scene {

    list_t *objects;
    sfColor opacity;
    shell_t *shell;
    sfClock *clock;

};

struct shell_s {
    textobject_t *lines[50];
    textobject_t *cursor;
    str_t *str_lines[50];
    shell_history_t *history;
    str_t *cmd;
    file_t *file;
    int cursor_pos;
    int cursor_pos_cmd;
    int line;
    sfFont *font;
    int width;
    int height;
    bool is_shift;
    sfSoundBuffer *sound_buffer;
    sfSound *sound;
};

struct shell_commands_s {
    char *name;
    void (*func)(shell_t *, char **);
};

struct shell_char_s {
    char c;
    void (*func)(void *obj);
};

struct shell_fix_key_s {
    char c;
    char fix;
};

void on_shell_render(void *scene);

void on_shell_event(void *scene, sfEvent *event);

void *on_shell_create(void);


//! Prompt

void display_prompt(shell_t *shell);

//! Commands

void command_manage(shell_t *shell);

void command_clear(shell_t *shell, char **args);
void command_rpg(shell_t *shell, char **args);
void command_rpgf(shell_t *shell, char **args);
void command_exit(shell_t *shell, char **args);
void command_history(shell_t *shell, char **args);
void command_help(shell_t *shell, char **args);
void command_ls(shell_t *shell, char **args);
void command_pwd(shell_t *shell, char **args);
void command_mkdir(shell_t *shell, char **args);
void command_cd(shell_t *shell, char **args);
void command_touch(shell_t *shell, char **args);
void command_bark(shell_t *shell, char **args);
void tartine(shell_t *shell, char **args);

char **shell_command_parse(char *path);

//! Print

void shell_print_line(shell_t *shell, char *str);
void shell_print(shell_t *shell, char *str);
void shell_print_nbr(shell_t *shell, int nbr);

void shell_add_new_line(shell_t *shell);

//! History

struct shell_history_s {
    str_t *cmd;
    shell_history_t *next;
    shell_history_t *prev;
};

void shell_history_append(shell_t *shell, char *cmd);

// KEY REBINDING
void dokey_classic_key(void *obj, char c, int key);

void dokey_escape(void *obj);
void dokey_lcontrol(void *obj);
void dokey_lshift(void *obj);
void dokey_lalt(void *obj);
void dokey_lsystem(void *obj);
void dokey_rcontrol(void *obj);
void dokey_rshift(void *obj);
void dokey_ralt(void *obj);
void dokey_rsystem(void *obj);
void dokey_menu(void *obj);
void dokey_enter(void *obj);
void dokey_backspace(void *obj);
void dokey_tab(void *obj);
void dokey_pageup(void *obj);
void dokey_pagedown(void *obj);
void dokey_end(void *obj);
void dokey_home(void *obj);
void dokey_insert(void *obj);
void dokey_delete(void *obj);
void dokey_left(void *obj);
void dokey_right(void *obj);
void dokey_up(void *obj);
void dokey_down(void *obj);
void dokey_f1(void *obj);
void dokey_f2(void *obj);
void dokey_f3(void *obj);
void dokey_f4(void *obj);
void dokey_f5(void *obj);
void dokey_f6(void *obj);
void dokey_f7(void *obj);
void dokey_f8(void *obj);
void dokey_f9(void *obj);
void dokey_f10(void *obj);
void dokey_f11(void *obj);
void dokey_f12(void *obj);
void dokey_f13(void *obj);
void dokey_f14(void *obj);
void dokey_f15(void *obj);
void dokey_pause(void *obj);

#endif //SHELL_H
