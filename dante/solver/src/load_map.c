/*
** EPITECH PROJECT, 2022
** dante [WSL: Ubuntu]
** File description:
** load_map
*/

#include "my.h"

void strsplit(solver_t *sol, char c)
{
    sol->size.x = 0;
    sol->size.y = 1;
    for (int i = 0; sol->file[i]; sol->file[i++] == c ? sol->size.y++ : 0) {};
    for (int i = 0; sol->file[i++] != c; sol->size.x++) {};
    sol->map = malloc(sizeof(char *) * (sol->size.y + 1));
    for (int i = 0; i < sol->size.y; i++) {
        sol->map[i] = my_calloc(sol->size.x + 1, sizeof(char));
        for (int j = 0; j < sol->size.x; j++) {
            sol->map[i][j] = sol->file[i * sol->size.x + j + i];
        }
    }
}

void load_file(char *filename, solver_t *sol)
{
    struct stat st;
    int size;
    int fd;

    stat(filename, &st);
    size = st.st_size;
    if ((fd = open(filename, O_RDONLY)) < 0)
        exit(82);
    sol->file = my_calloc(size + 1, 1);
    read(fd, sol->file, size);
    sol->map = (char **) my_calloc2d(size + 1, sizeof(char *));
    strsplit(sol, '\n');
    close(fd);
}
