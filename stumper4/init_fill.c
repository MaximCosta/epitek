/*
** EPITECH PROJECT, 2022
** init_fill
** File description:
** epitech > 42
*/

#include "my.h"

void fill_grid(data_t *data)
{
    char **word = data->word;
    int size = data->size;
    int next_size = 0;
    int next_id = 0;
    int y = 0;
    int x = 0;

    for (; (next_id = get_next(data)) != -1;) {
       next_size = strlen(word[next_id]);
       if (size >= (x + next_size))
           x = insert(data, word[next_size], x, y);
       else
           x = insert(data, word[next_size], 0, ++y);
       word[next_id][0] = '.';
    }
}

data_t *init_data()
{
    data_t *data = calloc(1, sizeof(data_t));

    if (data == NULL)
        return (NULL);
    data->size = 0;
    data->grid = NULL;
    data->words = NULL;
    data->word = NULL;
    return (data);
}
