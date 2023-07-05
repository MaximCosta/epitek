/*
** EPITECH PROJECT, 2022
** lemin [WSL: Ubuntu]
** File description:
** algo
*/

#include "my.h"

int in_visited(dijkstra_t *dijkstra, int node)
{
    int i = 0;

    for (; dijkstra->visited[i] != -1; i++)
        if (dijkstra->visited[i] == node)
            return (-1);
    return (i);
}

void rverese_array(int *arr, int start, int end)
{
    int temp;

    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void register_path(dijkstra_t *dij, parsing_t *par, int cur_node)
{
    int len_path = 0;
    for (int i = 0; cur_node != -1; i++) {
        dij->short_path[i] = cur_node;
        short_t *shortp = get_short(dij, cur_node);
        len_path = i;
        cur_node = shortp ? shortp->next : -1;
    }
    rverese_array(dij->short_path, 0, len_path);
    move_ant(dij, par, len_path);
}

void dijkstra_algo1(dijkstra_t *dij, int cur_node, int *dest, int wtcn)
{
    int wt = get_weight(dij, cur_node, *dest) + wtcn;
    int csw = 0;

    if (get_short(dij, *dest) == NULL)
        add_short(dij, *dest, cur_node, wt);
    else {
        csw = get_short(dij, *dest)->len;
        if (csw > wt)
            add_short(dij, *dest, cur_node, wt);
    }
}

void dijkstra_algo(dijkstra_t *dij, parsing_t *par)
{
    int start = get_node_from_name(dij, par->start->name)->id;
    int end = get_node_from_name(dij, par->end->name)->id;
    int cur_node = start;
    int *dest = NULL;
    int wtcn = 0;

    while (cur_node != end) {
        add_visted(dij, cur_node);
        dest = get_node(dij, cur_node)->path;
        wtcn = get_short(dij, cur_node)->len;
        for (; *dest != -1; dest++)
            dijkstra_algo1(dij, cur_node, dest, wtcn);
        cur_node = get_min_short(dij);
        if (cur_node == -1)
            return;
    }
    register_path(dij, par, cur_node);
}
