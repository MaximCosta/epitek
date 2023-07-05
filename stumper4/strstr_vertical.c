/*
** EPITECH PROJECT, 2022
** Duostumper 3
** File description:
** strstr vertical
*/

#include <string.h>

int bad_word_check(char ch_word, char **grid, int i, int *j)
{
    if (ch_word != grid[*j][i]) {
        return -1;
    }
    if (grid[*j + 1] != NULL)
        *j += 1;
    return 0;
}

int check_word(char **grid, char *word, int i, int j)
{
    for (int k = 0; word[k] != 0; k++) {
        if (bad_word_check(word[k], grid, i, &j) < 0)
            return 0;
        if (word[k + 1] == 0)
            return 1;
    }
    return 0;
}

int strstr_vert_check_word(char **grid, char *word, int i, int j)
{
    if (grid[j][i] == word[0]) {
        if (check_word(grid, word, i, j) > 0)
            return 1;
    }
    return 0;
}

int strstr_vert_check(char *word, char **grid, int i)
{
    for (int j = 0; grid[j] != NULL; j++) {
        if (strstr_vert_check_word(grid, word, i, j) > 0)
            return 1;
    }
    return 0;
}

int strstr_vertical(char *word, char **grid, int *count)
{
    for (int i = 0; i < strlen(grid[0]); i++) {
        if (strstr_vert_check(word, grid, i) > 0)
            *count += 1;
    }
    return 0;
}
