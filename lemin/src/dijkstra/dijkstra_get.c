/*
** EPITECH PROJECT, 2022
** lemin [WSL: Ubuntu]
** File description:
** dijkstra_get
*/

#include "my.h"

int get_idnode(dijkstra_t *dijkstra, int node)
{
    int i = 0;

    for (i = 0; dijkstra->nodes[i].id != -1; i++) {};
    if (dijkstra->nodes[i].id == node)
        return (i);
    return (-1);
}

nodes_t *get_node(dijkstra_t *dijkstra, int node)
{
    int i = 0;

    for (i = 0; dijkstra->nodes[i].id != -1; i++)
        if (dijkstra->nodes[i].id == node)
            return (&dijkstra->nodes[i]);
    return (NULL);
}

int get_weight(dijkstra_t *dijkstra, int n1, int n2)
{
    int f = -1;
    int i = 0;

    for (i = 0; dijkstra->nodes[i].id != -1; i++)
        if (dijkstra->nodes[i].id == n1) {
            f = i;
            break;
        }
    if (f == -1)
        return (-1);
    for (i = 0; dijkstra->nodes[f].path[i]; i++)
        if (dijkstra->nodes[f].path[i] == n2)
            return (dijkstra->nodes[f].path_len[i]);
    return (-1);
}

short_t *get_short(dijkstra_t *dijkstra, int node)
{
    int i = 0;

    for (i = 0; dijkstra->shortp[i].id != -1; i++)
        if (dijkstra->shortp[i].id == node)
            return (&dijkstra->shortp[i]);
    return (NULL);
}

int get_min_short(dijkstra_t *dij)
{
    int len = 2147483647;
    int min = -1;
    int i = 0;

    for (i = 0; dij->shortp[i].id != -1; i++) {
        if (in_visited(dij, dij->shortp[i].id) == -1)
            continue;
        len = min == -1 ? dij->shortp[i].len : 2147483647;
        if (dij->shortp[i].len > len)
            continue;
        min = i;
    }
    return (min != -1 ? dij->shortp[min].id : -1);
}
