/*
** EPITECH PROJECT, 2021
** Minishell1
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include <assert.h>
    #include <dirent.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <pwd.h>
    #include <signal.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <time.h>
    #include <unistd.h>
    #include "parsing.h"
typedef struct nodes_s {
    int *path_len;
    char *name;
    int *path;
    int id;
    int y;
    int x;
} nodes_t;
typedef struct short_s {
    int next;
    int len;
    int id;
} short_t;
typedef struct dijkstra_s {
    short_t *shortp;
    int *short_path;
    nodes_t *nodes;
    int *visited;
    int nb_nodes;
} dijkstra_t;

int my_atoi(char *str);
void *my_calloc(int nb, int size);
int my_strcmp(char *s1, char *s2);
int square(int nb);
char *my_strdup(char *str);

int get_idnode(dijkstra_t *dijkstra, int node);
nodes_t *get_node(dijkstra_t *dijkstra, int node);
int get_weight(dijkstra_t *dijkstra, int n1, int n2);
short_t *get_short(dijkstra_t *dijkstra, int node);
int get_min_short(dijkstra_t *dij);

void add_node(dijkstra_t *dijkstra, int node, int x, int y);
void add_path(dijkstra_t *dijkstra, int i1, int i2);
void add_visted(dijkstra_t *dijkstra, int node);
void add_short(dijkstra_t *dij, int node, int next, int len);

int in_visited(dijkstra_t *dijkstra, int node);
void dijkstra_algo(dijkstra_t *dij, parsing_t *par);

nodes_t *get_node_from_name(dijkstra_t *dij, char *name);
void init_path(nodes_t *n1, parsing_t *parsing, dijkstra_t *dij);
void init_dijkstra_node(dijkstra_t *dij, parsing_t *parsing);
void init_dijkstra(dijkstra_t *dij, parsing_t *parsing);

void move_ant(dijkstra_t *dij, parsing_t *par, int len);
#endif // MY.H //
