/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** rpg.c
*/

#include "../../../../../include/game/rpg.h"

int my_strncpm(char *str, char *str2, int n)
{
    int i = 0;

    for (i = 0; i < n - 1 && str[i] && str2[i] && str[i] == str2[i]; i++);
    return str[i] - str2[i];
}

static void change_scene(shell_t *shell, char *str)
{
    if (equal(str, "")) {
        shell_print(shell, "Please select a scene\n");
        shell_print(shell, "  intro      - Intro scene\n");
        shell_print(shell, "  p_intro    - Post Intro scene\n");
        shell_print(shell, "  menu       - Menu scene\n");
        shell_print(shell, "  load       - Load scene\n");
        shell_print(shell, "  game       - Game scene\n");
        shell_print(shell, "  spaceship  - Spaceship scene\n");
        return;
    }
    if (equal(str, "p_intro"))
        return scene_change(MAIN_SCENE);
    if (equal(str, "menu"))
        return scene_change(HOWPLAY_SCENE);
    if (equal(str, "intro"))
        return scene_change(GAME_SCENE);
    if (equal(str, "load"))
        return scene_change(LOAD_SCENE);
    if (equal(str, "game"))
        return scene_change(SWITCH_SCENE);
    if (equal(str, "spaceship"))
        return scene_change(SPACESHIP_SCENE);
    shell_print(shell, "Unknown scene '");
    shell_print(shell, str);
    shell_print(shell, "'\n");
}

void command_rpg(shell_t *shell, char **args)
{
    if (!args[1]) {
        shell_print(shell, "Segmentation fault (core dumped)\n");
        return;
    } else {
        if (equal(args[1], "--without-segfault"))
            return scene_change(LOAD_MENU);
        if (my_strncpm(args[1], "--scene=", 8) == 0)
            return change_scene(shell, args[1] + 8);
        if (equal(args[1], "-f"))
            return scene_change(MAIN_SCENE);
        if (equal(args[1], "--help") || equal(args[1], "-h")) {
            shell_print(shell, "RPG commands:\n");
            shell_print(shell, "  --scene=<scene>    - Change scene\n");
            shell_print(shell, "  --without-segfault - Don't segfault\n");
            shell_print(shell, "  --help             - Show this help\n");
            shell_print(shell, "  -f                 - Start game without intro\n");
            return;
        }
        shell_print(shell, "Unknown parameter: ");
        shell_print(shell, args[1]);
        shell_print(shell, "\n");
    }
}
