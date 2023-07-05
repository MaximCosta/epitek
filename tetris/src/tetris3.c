/*
** EPITECH PROJECT, 2022
** tetris [WSL: Ubuntu]
** File description:
** tetris3
*/

#include "../include/tetris.h"

char *rm_ext(char *str)
{
    int j = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == '.')
            j = i;
    str[j] = '\0';
    return (str);
}

int load_tetrimino(tetris_t *tetris, int count, DIR *dp, struct dirent *dirp)
{
    int pass = 1;
    int cur = 0;

    tetris->pieces = (api_t **) my_calloc2d(count + 2);
    while ((dirp = readdir(dp)) != NULL) {
        pass = 1;
        if (tetris->pieces[cur] == NULL)
            tetris->pieces[cur] = my_calloc(sizeof(api_t), 1);
        tetris->pieces[cur]->valid = 0;
        if (!check_extension(dirp->d_name))
            continue;
        if (load_tetrimino_prop(dirp->d_name, tetris->pieces[cur]) == -1)
            pass = 0;
        tetris->pieces[cur]->name = rm_ext(my_strdup(dirp->d_name));
        tetris->pieces[cur]->valid = pass;
        cur++;
    }
    tetris->nb_pieces = cur;
}

void clear_unuzed_tetrimino(tetris_t *tetris)
{
    for (int i = 0; tetris->pieces[i] != NULL; i++) {
        if (tetris->pieces[i]->valid == 0 && tetris->pieces[i]->name == NULL) {
            free(tetris->pieces[i]);
            tetris->pieces[i] = NULL;
        }
    }
}

int loader(tetris_t *tetris)
{
    int count = count_file("./tetriminos/");
    struct dirent *dirp;
    DIR *dp;

    if ((dp = opendir("./tetriminos")) == NULL)
        my_exit(84, "Error: Can't open directory\n");
    load_tetrimino(tetris, count, dp, dirp);
    closedir(dp);
    sort_struct_array(tetris, tetris->nb_pieces - 1);
    clear_unuzed_tetrimino(tetris);
}

tetris_t *init_struct(void)
{
    tetris_t *tetris = my_calloc(sizeof(tetris_t), 1);

    tetris->input = my_calloc(sizeof(input_t), 1);
    init_input(tetris->input);
    return (tetris);
}
