/*
** EPITECH PROJECT, 2022
** lemin [WSL: Ubuntu]
** File description:
** dijkstra_move
*/

#include "my.h"

typedef struct ants_s {
    int node;
    int ant;
} ants_t;

void my_put_nbr(int nb)
{
    char c;

    if (nb >= 10)
        my_put_nbr(nb / 10);
    c = nb % 10 + '0';
    write(1, &c, 1);
}

int move_ant2(dijkstra_t *dij, parsing_t *par, int len, ants_t *ants)
{
    char *name = NULL;
    int continuer = 0;

    for (int i = 0; i < par->nb_ants; i++) {
        if (ants[i].node == -1)
            continue;
        continuer = 1;
        write(1, "P", 1);
        my_put_nbr(ants[i].ant + 1);
        write(1, "-", 1);
        name = get_node(dij, dij->short_path[ants[i].node])->name;
        write(1, name, my_strlen(name));
        write(1, " ", 1);
        ants[i].node++;
        if (ants[i].node == (len + 1))
            ants[i].node = -1;
    }
    write(1, "\n", 1);
    return (continuer);
}

void move_ant(dijkstra_t *dij, parsing_t *par, int len)
{
    ants_t *ants = my_calloc(sizeof(ants_t), par->nb_ants + 1);
    int need = par->nb_ants;
    char *name = NULL;
    int continuer = 1;

    for (int i = 0; i < len; ants[i++].node = -1) {};
    while (continuer) {
        continuer = 0;
        if (need != 0) {
            ants[par->nb_ants - need].node = 1;
            ants[par->nb_ants - need].ant = par->nb_ants - need;
            need--;
        }
        continuer = move_ant2(dij, par, len, ants);
    }
}
