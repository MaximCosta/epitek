/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/

#ifndef GAME_H
    #define GAME_H

    #include "../rpg.h"
#define RIGHT right_press
    #define LEFT left_press
    #define UP up_press
    #define DOWN down_press
    #define ATTACK attack
    #define INVENTORY_O inventory_st
    #define DASH dash
    #define JETPACK jetpack
    #define ENERGY_ATTACK energy_attack
    #define HIT hit
    #define INTERACTION interaction
    #define PAUSE pause
    #define load_shield LOAD_SHIELD
    #define load_damage LOAD_DAMAGE
    #define load_speed LOAD_SPEED

typedef struct s_game game;
typedef struct s_inventory inventory_t;
typedef struct s_about about;
typedef struct s_toolbar toolbar_t;
typedef struct s_enemy enemy_t;
typedef struct s_mob mob_t;
typedef struct s_player player_t;
typedef struct s_flitem flitem_t;
typedef struct s_flidata flidata_t;
typedef struct s_fli_transfert fli_transfert_t;
typedef struct s_stats stats_t;
typedef struct s_quests quests_t;
typedef struct s_trader trader_t;
typedef struct s_menu menu_t;
typedef struct s_input input_t;
typedef struct s_slider slider_t;

struct s_about {
    char *name;
    textobject_t *name_text;
    char *description;
    char *filepath;
    char *image_item;
    char *image_flitem;
};

struct s_slider {
    object_t *slider;
    textobject_t *text;
    bool take;
    V2F size;
};

struct s_input {
    int right;
    int left;
    int up;
    int down;
    int interact;
    int inventory;
    int jet_pack;
    int DASH;
};

struct s_menu {
    bool active;
    object_t *resume;
    object_t *save;
    object_t *restart;
    object_t *back_to_menu;
    object_t *leave;
    textobject_t *right_key;
    textobject_t *left_key;
    textobject_t *up_key;
    textobject_t *down_key;
    textobject_t *interact_key;
    textobject_t *inventory_key;
    textobject_t *dash_key;
    textobject_t *jetpack_key;
    object_t *right_o;
    object_t *left_o;
    object_t *up_o;
    object_t *down_o;
    object_t *interact_o;
    object_t *inventory_o;
    object_t *dash_o;
    object_t *jetpack_o;
    bool edit_key;
    object_t *invincibility;
    object_t *auto_save;
    int edit;
    int input;
};

struct s_trader {
    object_t *trader;
    object_t *trader_panel;
    bool active;
    bool click;
    object_t **payment;
};
struct s_fli_transfert {
    char *name;
    int id_link;
    char *description;
    char *filepath;
    char *image_item;
    char *image_flitem;
};

struct s_flidata {
    object_t *item;
    textobject_t *name;
    char *description;
    int id_link;
    int initial_pos;
    int animation_path;
    char *filepath;
    char *image_item;
    char *image_flitem;
    char *data;
};

struct s_flitem {
    flidata_t *data;
    flitem_t *next;
};

struct s_inventory {
    object_t *box;
    object_t *item;
    about info;
    bool selected;
};

struct s_stats {
    bool active;
    int dolex;
    bool LOAD_SHIELD;
    bool LOAD_DAMAGE;
    bool LOAD_SPEED;
    object_t *lock;
    bool is_lock;
};

struct s_enemy {
    int pvmax;
    int pv;
    int speed;
    int damage;
    int vision;
    int detection;
    int distance_attack;
    DeltaTime delta;
    DeltaTime dattack;
    float as;
    char *type;
    int delay;
    int top_attack;
    int top_idle;
    int top_run;
    int top_damage;
    int xpdrop;
    char *state;
    textobject_t *pv_text;
    sfVector2f dimension;
};

struct s_mob {
    int id;
    enemy_t *data;
    object_t *mob;
    mob_t *next;
};

struct s_quests {
    bool active;
    object_t *lock;
    bool is_lock;
    bool main_quest_active;
    int n_quests;
    bool on_click;
    int n_redstone;
    int n_emeraude;
    int n_lapis;
};

struct s_toolbar {
    int pv;
    object_t **actions;
};

enum game_objects {
    BACKGROUND_MAP,
    PLAYER,
    INVENTORY,
    BLACKSCREEN_GAME,
    CURSOR_GAME,
    CASE,
    ITEM_RESURRECTION,
    INFO,
    INFO_NAME,
    INFO_DESCRIPTION,
    EQUIPED,
    EQUIPED_NAME,
    PV_BACK,
    PV,
    TOOLBAR,
    ACTION,
    KEY_ACTION,
    E_BIG,
    E_DROID,
    E_PHANTOM,
    PV_TEXT,
    MONEY,
    FLI_MONEY,
    TOOLXP_BACK,
    TOOLXP_FRONT,
    PLAYER_ICON,
    PLAYER_LVL_TEXT,
    MOUSE_STATE,
    PLAYER_STATS_BTN,
    PLAYER_STATS,
    STATS_MAXPV_TXT,
    STATS_DAMAGE_TXT,
    STATS_SPEED_TXT,
    INFO_SHIELD,
    INFO_DAMAGE,
    INFO_SPEED,
    INFO_DOLEX,
    LOAD_SHIELD,
    LOAD_DAMAGE,
    LOAD_SPEED,
    DOLEX_TXT,
    QUESTS_BTN,
    PLAYER_QUESTS,
    LOCK,
    TRADER,
    TRADER_MESSAGE,
    TRADER_PANEL,
    WALLET,
    TRADER_INFO_BTN,
    TRADER_INFO,
    MAP_BACK,
    ACCEPT_QUEST,
    MAIN_QUEST,
    MAIN_QUEST_DISTANCE,
    OBJECTIVES_QUEST,
    INDICATOR,
    LAPIS,
    REDSTONE,
    EMERAUDE,
    LAPIS_FLI,
    REDSTONE_FLI,
    EMERAUDE_FLI,
    LAPIS_TEXT,
    REDSTONE_TEXT,
    EMERAUDE_TEXT,
    QUESTS_ACCPET_BTN,
    ACCEPT_MSG,
    PLAYER_PROFILE_GUI,
    PLAYER_PROFILE_GUI_NAME_EDIT,
    PLAYER_PROFILE_GUI_PLAYER,
    SETTINGS_MENU,
    M_RESUME,
    M_SAVE,
    M_RESTART,
    M_BACK_TO_MENU,
    M_LEAVE,
    M_RIGHT_KEY_T,
    M_LEFT_KEY_T,
    M_UP_KEY_T,
    M_DOWN_KEY_T,
    M_INTERACT_KEY_T,
    M_INVENTORY_KEY_T,
    M_DASH_KEY_T,
    M_JETPACK_KEY_T,
    M_RIGHT_O,
    M_LEFT_O,
    M_UP_O,
    M_DOWN_O,
    M_INTERACT_O,
    M_INVENTORY_O,
    M_DASH_O,
    M_JETPACK_O,
    M_ANY_KEY,
    INVINCIBILITY,
    AUTO_SAVE,
    FPS_SLIDER,
    TEXT_FPS,
    VOLUME_SLIDER,
    TEXT_VOLUME,
};

struct s_player {
    bool RIGHT;
    bool LEFT;
    bool UP;
    bool DOWN;
    bool ATTACK;
    bool INVENTORY_O;
    bool is_profile_gui_opened;
    bool DASH;
    bool JETPACK;
    bool ENERGY_ATTACK;
    bool HIT;
    bool INTERACTION;
    bool PAUSE;
    int damage;
    int energy_damage;
    int money;
    int lvl;
    int xp;
    int xp_max;
    int pv_max;
    float speed;
};

struct s_game {

    list_t *objects;
    bool mouse_press;
    player_t *player;
    int *dash_move;
    int save_hover;
    int jet_power;
    int energy_power;
    char **map;
    mob_t *mobs;
    toolbar_t *toolbar;
    inventory_t *cases;
    inventory_t *equiped;
    sfView *view;
    flitem_t *flitem;
    int nb_enemy;
    stats_t *stats;
    quests_t *quests;
    trader_t *trader;
    menu_t *menu;
    input_t *key_input;
    int difficulty;
    bool game_destroyed;
    sfImage *color_palette;
};

void on_game_render(void *scene);

void on_game_event(void *scene, sfEvent *event);

void *on_game_create(void);

#endif //GAME_H
