/*
** EPITECH PROJECT, 2022
** lemin [WSL: Ubuntu]
** File description:
** dijkstra_add
*/

#include "my.h"

void add_node(dijkstra_t *dijkstra, int node, int x, int y)
{
    int i = 0;

    for (; dijkstra->nodes[i].id != -1; i++) {};
    dijkstra->nodes[i].id = node;
    dijkstra->nodes[i].x = x;
    dijkstra->nodes[i].y = y;
    dijkstra->nodes[i].path = my_calloc(5, dijkstra->nb_nodes);
    dijkstra->nodes[i].path_len = my_calloc(5, dijkstra->nb_nodes);
}

void add_path(dijkstra_t *dijkstra, int i1, int i2)
{
    nodes_t *n1 = get_node(dijkstra, i1);
    nodes_t *n2 = get_node(dijkstra, i2);
    int weight = -1;
    int i = 0;

    if (n1 == NULL || n1 == NULL)
        return;
    weight = square(n1->x - n2->x) + square(n1->y - n2->y);
    for (i = 0; n1->path[i]; i++) {};
    n1->path[i] = i2;
    n1->path_len[i] = weight;
    for (i = 0; n2->path[i]; i++) {};
    n2->path[i] = i1;
    n2->path_len[i] = weight;
}

void add_visted(dijkstra_t *dijkstra, int node)
{
    int i = 0;

    if ((i = in_visited(dijkstra, node)) == -1)
        return;
    dijkstra->visited[i] = node;
}

void add_short(dijkstra_t *dij, int node, int next, int len)
{
    int i = 0;

    for (; dij->shortp[i].id != -1 && dij->shortp[i].id != node; i++) {};
    dij->shortp[i].id = node;
    dij->shortp[i].next = next;
    dij->shortp[i].len = len;
}
