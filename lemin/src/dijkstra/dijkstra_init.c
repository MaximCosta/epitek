/*
** EPITECH PROJECT, 2022
** lemin [WSL: Ubuntu]
** File description:
** dijkstra_init
*/

#include "my.h"

nodes_t *get_node_from_name(dijkstra_t *dij, char *name)
{
    int i = 0;

    for (; dij->nodes[i].name != NULL; i++)
        if (my_strcmp(dij->nodes[i].name, name) == 0)
            return (&dij->nodes[i]);
    return (NULL);
}

void init_path(nodes_t *n1, parsing_t *parsing, dijkstra_t *dij)
{
    parsing_links_t *links = parsing->links;
    nodes_t *n2 = NULL;

    for (int i = 0; links; links = links->next) {
        if (my_strcmp(links->room_1, n1->name) == 0) {
            n2 = get_node_from_name(dij, links->room_2);
            n1->path[i] = n2->id;
            n1->path_len[i] = square(n1->x - n2->x) + square(n1->y - n2->y);
            i++;
        }
        if (my_strcmp(links->room_2, n1->name) == 0) {
            n2 = get_node_from_name(dij, links->room_1);
            n1->path[i] = n2->id;
            n1->path_len[i] = square(n1->x - n2->x) + square(n1->y - n2->y);
            i++;
        }
    }
}

void init_dijkstra_node2(dijkstra_t *dij, parsing_t *parsing)
{
    for (int i = 0; i < dij->nb_nodes; i++) {
        for (int j = 0; j < dij->nb_nodes; j++) {
            dij->nodes[i].path_len[j] = -1;
            dij->nodes[i].path[j] = -1;
        }
        init_path(&dij->nodes[i], parsing, dij);
    }
}

void init_dijkstra_node(dijkstra_t *dij, parsing_t *parsing)
{
    parsing_rooms_t *rooms = parsing->rooms;

    dij->nb_nodes = 0;
    for (; rooms; rooms = rooms->next)
        dij->nb_nodes++;
    dij->nodes = my_calloc(sizeof(nodes_t), dij->nb_nodes + 1);
    rooms = parsing->rooms;
    for (int i = 0; i < dij->nb_nodes; i++) {
        dij->nodes[i].id = i;
        dij->nodes[i].x = rooms->x;
        dij->nodes[i].y = rooms->y;
        dij->nodes[i].name = my_strdup(rooms->name);
        dij->nodes[i].path = my_calloc(sizeof(int), dij->nb_nodes + 1);
        dij->nodes[i].path_len = my_calloc(sizeof(int), dij->nb_nodes + 1);
        rooms = rooms->next;
    }
    init_dijkstra_node2(dij, parsing);
}

void init_dijkstra(dijkstra_t *dij, parsing_t *parsing)
{
    nodes_t *n2 = NULL;

    init_dijkstra_node(dij, parsing);
    dij->shortp = my_calloc(dij->nb_nodes + 1, sizeof(short_t));
    dij->visited = my_calloc(dij->nb_nodes + 1, sizeof(int));
    dij->short_path = my_calloc(dij->nb_nodes + 1, sizeof(int));
    for (int i = 0; i < dij->nb_nodes + 1; i++) {
        dij->shortp[i].id = -1;
        dij->shortp[i].next = -1;
        dij->shortp[i].len = -1;
        dij->visited[i] = -1;
        dij->short_path[i] = -1;
    }
    n2 = get_node_from_name(dij, parsing->start->name);
    dij->shortp[0].id = n2->id;
    dij->shortp[0].next = -1;
    dij->shortp[0].len = 0;
}
