/*
** EPITECH PROJECT, 2022
** stumper04
** File description:
** word_in_2darray
*/

#include "my.h"

int words_in_2darray(data_t *data, char *buffer)
{
    int count;
    char *save = buffer;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            count++;
    }
    data->words = calloc(data->size + 1, sizeof(char));
    data->words[0] = strtok(buffer, "\n");
    for (int i = 1; i < count; i++) {
        data->words[i] = strtok(NULL, "\n");
    }
    free(buffer);
    return 0;
}
