/*
** EPITECH PROJECT, 2022
** algo
** File description:
** you're a bad developer
*/

#include "./include/my.h"

int life_algo_main(char **map, int nb_loop, int size_y, int size_x)
{
    int err;

    for (int i = 0; i < nb_loop; i++)
        life_algo_loop(map, size_y, size_x);
    for (int i = 0; map[i] != NULL; i++) {
        err = printf("%s\n", map[i]);
        if (err == -1)
            exit(84);
    }
    free_map(map);
    return 0;
}

int life_algo_loop(char **map, int size_y, int size_x)
{
    char **new_map = strdup_2d(map, size_y + 1, size_x);

    for (int y = 0; map[y] != NULL; y++)
        for (int x = 0; map[y][x] != '\0'; x++)
            life_algo(map, new_map, y, x);
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0'; x++) {
            map[y][x] = new_map[y][x];
        }
    }
    free_map(new_map);
    return 0;
}

int ck(char **map, int y, int x)
{
    if (map[y] == NULL)
        return 0;
    if (x < 0 || y < 0)
        return 0;
    if (map[y][x] == 0)
        return 0;
    return (map[y][x] == 'X' ? 1 : 0);
}

int life_algo_replace(char s, int nb)
{
    if (s == 'X' && nb >= 4)
        return '.';
    if (s == '.' && nb == 3)
        return 'X';
    if (s == 'X' && nb <= 1)
        return '.';
    return s;
}

int life_algo(char **map, char **new_map, int y, int x)
{
    int cor[8][2] = {
        {-1, -1}, {-1, 0},
        {-1, 1}, {0, -1}, 
        {0, 1}, {1, -1}, 
        {1, 0}, {1, 1}
    };
    int count = 0;
    char t;

    for (int i = 0; i < 8; i++)
        if (ck(map, y + cor[i][0], x + cor[i][1]) == 1)
            count++;
    t = life_algo_replace(map[y][x], count);
    if (t != map[y][x])
        new_map[y][x] = t;
    return 0;
}
