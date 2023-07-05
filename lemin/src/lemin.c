/*
** EPITECH PROJECT, 2021
** src
** File description:
** main.c
*/

#include "my.h"

int main(void)
{
    dijkstra_t *dij = my_calloc(sizeof(dijkstra_t), 1);
    parsing_t *parsing = do_parsing();

    if (!parsing)
        return 84;
    parsing_rooms_t *rooms = parsing->rooms;
    init_dijkstra(dij, parsing);
    dijkstra_algo(dij, parsing);
    parsing_destroy(parsing);
    return 0;
}
