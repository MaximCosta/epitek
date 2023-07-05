/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** simple_key.c
*/

#include "../../../../../include/game/rpg.h"

static const shell_fix_key_t shell_fix_keys[] = {
    {27, '&'}, {28, 'e'}, {29, '"'}, {51, '\''}, {31, '('},
    {56, '-'}, {33, 'e'}, {34, '_'}, {35, 'c'}, {26, 'a'},
    {56, ')'}, {55, '='}, {52, ':'},
    {0, 0},
};

static const shell_fix_key_t shell_fix_majs[] = {
    {':', '/'}, {';', '.'},
    {'&', '1'}, {'e', '2'}, {'"', '3'}, {'\'', '4'}, {'(', '5'},
    {'-', '6'}, {'e', '7'}, {'_', '8'}, {'c', '9'}, {'a', '0'},
    {0, 0}
};

char shell_fix_key(shell_t *shell, int key, char c)
{
    for (int i = 0; shell_fix_keys[i].c; i++) {
        if (shell_fix_keys[i].c == key)
            return shell_fix_keys[i].fix;
    }
    return c;
}

char shell_fix_maj(shell_t *shell, int key, char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 32;
    for (int i = 0; shell_fix_majs[i].c; i++) {
        if (shell_fix_majs[i].c == c)
            return shell_fix_majs[i].fix;
    }
    return c;
}

void dokey_classic_key(void *obj, char c, int key)
{
    shell_scene_t *scene_menu = (shell_scene_t *) obj;
    shell_t *shell = scene_menu->shell;

    c = shell_fix_key(shell, key, c);
    if (shell->is_shift)
        c = shell_fix_maj(shell, key, c);
    if (shell->cursor_pos >= shell->width)
        return;
    str_add_char_pos(shell->cmd, c, shell->cursor_pos_cmd);
    str_add_char_pos(shell->str_lines[shell->line], c, shell->cursor_pos);
    shell->cursor_pos++;
    shell->cursor_pos_cmd++;
}