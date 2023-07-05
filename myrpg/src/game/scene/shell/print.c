/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** print.c
*/

#include "../../../../include/game/rpg.h"

void shell_add_new_line(shell_t *shell)
{
    str_t *tmp = NULL;

    shell->cursor_pos = 0;
    if (shell->line < shell->height - 1)
        shell->line++;
    else {
        str_clear(shell->str_lines[0]);
        tmp = shell->str_lines[0];
        for (int i = 0; i < shell->height - 1; i++)
            shell->str_lines[i] = shell->str_lines[i + 1];
        shell->str_lines[shell->height - 1] = tmp;
    }
}

void shell_print_line(shell_t *shell, char *str)
{
    shell_print(shell, str);
    shell_add_new_line(shell);
}

void shell_add_char_to_line(shell_t *shell, char c)
{
    if (shell->str_lines[shell->line]->len < shell->width) {
        str_add_char(shell->str_lines[shell->line], c);
        shell->cursor_pos++;
    } else {
        shell_add_new_line(shell);
        return shell_add_char_to_line(shell, c);
    }
}

void shell_print(shell_t *shell, char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n') {
            shell_add_new_line(shell);
            continue;
        }
        shell_add_char_to_line(shell, str[i]);
    }
}

void shell_print_nbr(shell_t *shell, int nbr)
{
    char str[2] = {0};

    if (nbr < 0) {
        nbr *= -1;
        shell_print(shell, "-");
    }
    if (nbr == 0)
        shell_print(shell, "0");
    while (nbr != 0) {
        str[0] = nbr % 10 + '0';
        nbr /= 10;
        shell_print(shell, str);
    }
}
