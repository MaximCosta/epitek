/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-lemin-flavio.moreno
** File description:
** parsing_init.c
*/

#include "my.h"

parsing_t *parsing_create(void)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    if (!parsing)
        return (NULL);
    parsing->nb_ants = 0;
    parsing->rooms = NULL;
    parsing->links = NULL;
    parsing->start = NULL;
    parsing->end = NULL;
    return (parsing);
}

parsing_t *parsing_destroy(parsing_t *parsing)
{
    if (!parsing)
        return (NULL);
    parsing_rooms_destroy(parsing->rooms);
    parsing_links_destroy(parsing->links);
    free(parsing);
    return (NULL);
}
