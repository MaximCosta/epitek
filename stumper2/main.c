/*
** EPITECH PROJECT, 2022
** main
** File description:
** no, real programmers use cat
*/

#include "./include/my.h"

int main(int ac, char *av[])
{
    char **map;
    char *buffer;
    int nb_loop;
    int col;
    int row;

    if (ac != 3)
        exit(84);
    nb_loop = atoi(av[2]);
    if (nb_loop < 0)
        exit(84);
    buffer = load_file_in_mem(av[1]);
    check_file(buffer);
    col = count_cols(buffer);
    row = count_rows(buffer);
    map = str_to_array(buffer, col, row);
    life_algo_main(map, nb_loop, row, col);
    free(buffer);
    return (0);
}
