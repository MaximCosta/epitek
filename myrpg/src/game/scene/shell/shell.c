/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/

#include "../../../../include/game/rpg.h"

static const char *FONT = "./assets/shell/font.ttf";
static const char *BARK = "./assets/shell/bark.ogg";
static const shell_char_t list_chars[] = {
    {'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, {'g', 0},
    {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0},
    {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0}, {'u', 0},
    {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0},
    {'0', 0}, {'1', 0}, {'2', 0}, {'3', 0}, {'4', 0}, {'5', 0}, {'6', 0},
    {'7', 0}, {'8', 0}, {'9', 0},
    {0, &dokey_escape}, {0, dokey_lcontrol}, {0, &dokey_lshift},
    {0, &dokey_lalt}, {0, &dokey_lsystem},
    {0, &dokey_rcontrol}, {0, &dokey_rshift}, {0, &dokey_ralt},
    {0, &dokey_rsystem}, {0, &dokey_menu},
    {'[', 0}, {']', 0}, {';', 0}, {',', 0}, {'.', 0}, {'`', 0},
    {'/', 0}, {'\\', 0}, {'~', 0}, {'=', 0}, {'-', 0}, {' ', 0},
    {0, &dokey_enter}, {0, &dokey_backspace}, {0, &dokey_tab},
    {0, &dokey_pageup}, {0, &dokey_pagedown},
    {0, &dokey_end}, {0, &dokey_home}, {0, &dokey_insert}, {0, &dokey_delete},
    {'+', 0}, {'-', 0}, {'*', 0}, {'/', 0},
    {0, &dokey_left}, {0, &dokey_right}, {0, &dokey_up}, {0, &dokey_down},
    {'0', 0}, {'1', 0}, {'2', 0}, {'3', 0}, {'4', 0}, {'5', 0}, {'6', 0},
    {'7', 0}, {'8', 0}, {'9', 0},
    {0, &dokey_f1}, {0, &dokey_f2}, {0, &dokey_f3}, {0, &dokey_f4},
    {0, &dokey_f5}, {0, &dokey_f6}, {0, &dokey_f7},
    {0, &dokey_f8}, {0, &dokey_f9}, {0, &dokey_f10}, {0, &dokey_f11},
    {0, &dokey_f12}, {0, &dokey_f13}, {0, &dokey_f14},
    {0, &dokey_f15}, {0, &dokey_pause},
};

void on_shell_render(void *scene)
{
    shell_scene_t *scene_menu = (shell_scene_t *) scene;
    sfVector2f p = sfText_findCharacterPos(
        scene_menu->shell->lines[scene_menu->shell->line]->text,
        scene_menu->shell->cursor_pos);
    static sfVector2f p_old = {0, 0};

    textobject_set_position(scene_menu->shell->cursor,
    (sfVector2f) {p.x - 5, p.y});
    for (int i = 0; i < scene_menu->shell->height; i++)
        textobject_set_string(scene_menu->shell->lines[i],
                scene_menu->shell->str_lines[i]->str);
    if (elapsed_time_milliseconds(450, &p_old.x, &p_old.y))
        scene_menu->shell->cursor->object->visible ^= 1;
    scene_render(scene_menu->objects);
}

void on_shell_event(void *scene, sfEvent *event)
{
    shell_scene_t *scene_menu = (shell_scene_t *) scene;

    if (event->type == sfEvtKeyPressed && event->key.code != -1) {
        if (event->key.code == sfKeyLShift || event->key.code == sfKeyRShift)
            scene_menu->shell->is_shift = 1;
        if (list_chars[event->key.code].c)
            dokey_classic_key(scene_menu, list_chars[event->key.code].c,
                                event->key.code);
        else
            list_chars[event->key.code].func(scene_menu);
    }
    if (event->type == sfEvtKeyReleased && event->key.code != -1) {
        if (event->key.code == sfKeyLShift || event->key.code == sfKeyRShift)
            scene_menu->shell->is_shift = 0;
    }
    scene_handle_events(scene_menu->objects, event);
}

void *on_shell_create(void)
{
    shell_scene_t *scene = my_calloc(sizeof(SpaceShip));
    textobject_t *text = NULL;

    scene->clock = sfClock_create();
    scene->shell = my_calloc(sizeof(shell_t));
    scene->shell->font = sfFont_createFromFile(FONT);
    scene->shell->width = 160;
    scene->shell->height = 49;
    scene->shell->cursor = textobject_create(50, (loc_t) {0, 0}, "|");
    scene->shell->cmd = str_create_size(256);
    scene->shell->sound_buffer = sfSoundBuffer_createFromFile(BARK);
    scene->shell->sound = sfSound_create();
    sfSound_setBuffer(scene->shell->sound, scene->shell->sound_buffer);
    textobject_set_font(scene->shell->cursor, scene->shell->font);
    textobject_set_size(scene->shell->cursor, 20);
    sfText_setColor(scene->shell->cursor->text, sfColor_fromRGB(138, 138, 138));
    for (int i = 0; i < 49; i++) {
        scene->shell->lines[i] = textobject_create(i, (loc_t) {0, i * 22}, "");
        textobject_set_font(scene->shell->lines[i], scene->shell->font);
        textobject_set_size(scene->shell->lines[i], 20);
        sfText_setLetterSpacing(scene->shell->lines[i]->text, 1.2);
        scene_add_text(&scene->objects, scene->shell->lines[i]);
        scene->shell->str_lines[i] = str_create_size(256);
    }
    path_add_elem(&scene->shell->file, create_folder("/"));
    scene_add_text(&scene->objects, scene->shell->cursor);
    display_prompt(scene->shell);
    return scene;
}
