/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** functions.c
*/

#include "../../../../../include/game/rpg.h"

void dokey_lcontrol(void *obj)
{

}

void dokey_lshift(void *obj)
{

}

void dokey_lalt(void *obj)
{

}

void dokey_lsystem(void *obj)
{

}

void dokey_rcontrol(void *obj)
{

}

void dokey_rshift(void *obj)
{

}

void dokey_ralt(void *obj)
{

}

void dokey_rsystem(void *obj)
{

}

void dokey_menu(void *obj)
{

}

void dokey_enter(void *obj)
{
    shell_scene_t *scene_menu = (shell_scene_t *) obj;
    shell_t *shell = scene_menu->shell;
    str_t *tmp = NULL;

    shell->cursor_pos = 0;
    shell->cursor_pos_cmd = 0;
    shell_add_new_line(shell);
    command_manage(shell);
    str_clear(shell->cmd);
    display_prompt(shell);
}

void dokey_backspace(void *obj)
{
    shell_scene_t *scene_menu = (shell_scene_t *) obj;
    shell_t *shell = scene_menu->shell;

    if (!shell->cursor_pos_cmd)
        return;
    str_remove_char_pos(shell->cmd, shell->cursor_pos_cmd - 1);
    str_remove_char_pos(shell->str_lines[shell->line], shell->cursor_pos - 1);
    shell->cursor_pos--;
    shell->cursor_pos_cmd--;
}

void dokey_tab(void *obj)
{

}

void dokey_pageup(void *obj)
{

}

void dokey_pagedown(void *obj)
{

}

void dokey_end(void *obj)
{

}

void dokey_home(void *obj)
{

}

void dokey_insert(void *obj)
{

}

void dokey_delete(void *obj)
{
    shell_scene_t *scene_menu = (shell_scene_t *) obj;
    shell_t *shell = scene_menu->shell;

    if (shell->cursor_pos_cmd >= shell->cmd->len)
        return;
    str_remove_char_pos(shell->cmd, shell->cursor_pos_cmd);
    str_remove_char_pos(shell->str_lines[shell->line], shell->cursor_pos);
}

void dokey_left(void *obj)
{
    shell_scene_t *scene_menu = (shell_scene_t *) obj;
    shell_t *shell = scene_menu->shell;

    if (shell->cursor_pos_cmd) {
        shell->cursor_pos--;
        shell->cursor_pos_cmd--;
    }
}

void dokey_right(void *obj)
{
    shell_scene_t *scene_menu = (shell_scene_t *) obj;
    shell_t *shell = scene_menu->shell;

    if (shell->cursor_pos_cmd != shell->cmd->len) {
        shell->cursor_pos++;
        shell->cursor_pos_cmd++;
    }
}

void shell_clear_cmd(shell_t *shell)
{
    while (shell->cmd->len) {
        str_remove_last(shell->cmd);
        str_remove_last(shell->str_lines[shell->line]);
    }
    shell->cursor_pos = shell->str_lines[shell->line]->len;
    shell->cursor_pos_cmd = 0;
}

void dokey_up(void *obj)
{
    shell_scene_t *scene_menu = (shell_scene_t *) obj;
    shell_t *shell = scene_menu->shell;

    if (shell->history) {
        shell_clear_cmd(shell);
        shell_print(shell, shell->history->cmd->str);
        str_add_str(shell->cmd, shell->history->cmd);
        shell->cursor_pos_cmd = shell->cmd->len;
        if (shell->history->prev)
            shell->history = shell->history->prev;
    }
}

void dokey_down(void *obj)
{
    shell_scene_t *scene_menu = (shell_scene_t *) obj;
    shell_t *shell = scene_menu->shell;

    if (shell->history && shell->history->next) {
        shell->history = shell->history->next;
        shell_clear_cmd(shell);
        shell_print(shell, shell->history->cmd->str);
        str_add_str(shell->cmd, shell->history->cmd);
        shell->cursor_pos_cmd = shell->cmd->len;
        return;
    }
    if (shell->history && !shell->history->next)
        shell_clear_cmd(shell);
}

void dokey_f1(void *obj)
{

}

void dokey_f2(void *obj)
{

}

void dokey_f3(void *obj)
{

}

void dokey_f4(void *obj)
{

}

void dokey_f5(void *obj)
{

}

void dokey_f6(void *obj)
{

}

void dokey_f7(void *obj)
{

}

void dokey_f8(void *obj)
{

}

void dokey_f9(void *obj)
{

}

void dokey_f10(void *obj)
{

}

void dokey_f11(void *obj)
{

}

void dokey_f12(void *obj)
{

}

void dokey_f13(void *obj)
{

}

void dokey_f14(void *obj)
{

}

void dokey_f15(void *obj)
{

}

void dokey_pause(void *obj)
{

}
