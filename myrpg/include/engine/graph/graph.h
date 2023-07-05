/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef GRAPH_H
    #define GRAPH_H

typedef struct s_graph Graph;

struct s_graph {

    Graph *next;
    void *value;

};

void graph_delete_node(Graph *node);

void graph_delete(Graph **node);

Graph *graph_create_node(void *value);

void graph_insert_end(Graph **node, void *value);

void graph_delete_last_node(Graph **list);

#endif //GRAPH_H
