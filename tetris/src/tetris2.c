/*
** EPITECH PROJECT, 2022
** tetris [WSL: Ubuntu]
** File description:
** tetris2
*/

#include "../include/tetris.h"

int check_shape_param(char *line, api_t *pieces)
{
    char *width = strtok(line, " \n");
    char *height = strtok(NULL, " \n");
    char *color = strtok(NULL, " \n");

    if (isnbr(width) == 0 || isnbr(height) == 0 || isnbr(color) == 0)
        return -1;
    pieces->width = my_atoi(width);
    pieces->height = my_atoi(height);
    pieces->color = my_atoi(color);
    if (pieces->width <= 0 || pieces->height <= 0 || pieces->color < 0
        || pieces->color > 7)
        return -1;
    return 0;
}

int closed_file(char *line, FILE *fp, int code)
{
    if (line != NULL)
        free(line);
    fclose(fp);
    return code;
}

int load_tetrimino_prop(char *filename, api_t *pieces)
{
    char *full_name = my_strcat("./tetriminos/", filename);
    FILE *fp = fopen(full_name, "r");
    char *line = NULL;
    size_t size = 0;

    free(full_name);
    if (fp == NULL)
        return -1;
    getline(&line, &size, fp);
    line = my_strdump(line);
    if (check_shape_param(line, pieces) == -1)
        return closed_file(line, fp, -1);
    if (load_tetrimino_shape(fp, pieces) == -1)
        return closed_file(line, fp, -1);
    return closed_file(line, fp, 0);
}

int check_extension(char *file)
{
    int j = 0;

    for (int i = 0; file[i]; i++)
        if (file[i] == '.')
            j = i + 1;
    if (my_strncmp(file + j, "tetrimino", 10) == 0)
        return (1);
    return (0);
}

int count_file(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *file;
    int count = 0;

    if (dir == NULL)
        my_exit(84, "Error: Can't open directory\n");
    for (; (file = readdir(dir)) != NULL;)
        if (file->d_name[0] != '.')
            count++;
    closedir(dir);
    return (count);
}
