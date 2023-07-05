/*
** EPITECH PROJECT, 2022
** Duostumper 4
** File description:
** count words in grid
*/

#include <stdio.h>
#include <string.h>

int strstr_vertical(char *word, char **grid, int *count);

int find_word(char *word, char **grid, int *count)
{
    for (int i = 0; grid[i] != NULL; i++) {
        if (strstr(word, grid[i]) != NULL)
            *count += 1;
    }
    strstr_vertical(word, grid, count);
    return 0;
}

int count_words_in_grid(char **words, char **grid)
{
    int count = 0;
    
    for (int i = 0; words[i] != NULL; i++) {
        find_word(words[i], grid, &count);
    }
    return count;
}
