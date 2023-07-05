/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-lemin-flavio.moreno [WSL: Ubuntu-20.04]
** File description:
** parsing_append.c
*/

#include "my.h"

int parsing_rooms_append(parsing_t *parsing, char *content,
                        int is_start, int is_end)
{
    parsing_rooms_t *rooms = parsing->rooms;
    parsing_rooms_t *new_room = parsing_rooms_create(content);

    if (!new_room)
        return 1;
    parsing->start = is_start ? new_room : parsing->start;
    parsing->end = is_end ? new_room : parsing->end;
    if (!rooms) {
        parsing->rooms = new_room;
        return 0;
    }
    for (; rooms->next; rooms = rooms->next);
    rooms->next = new_room;
    return 0;
}

void parsing_rooms_destroy(parsing_rooms_t *rooms)
{
    if (!rooms)
        return;
    parsing_rooms_destroy(rooms->next);
    free(rooms->data);
    free(rooms);
}

int parsing_links_append(parsing_t *parsing, char *content)
{
    parsing_links_t *links = parsing->links;
    parsing_links_t *new_link = parsing_links_create(content);

    if (!new_link)
        return 1;
    if (!links) {
        parsing->links = new_link;
        return 0;
    }
    for (; links->next; links = links->next);
    links->next = new_link;
    return 0;
}

void parsing_links_destroy(parsing_links_t *links)
{
    if (!links)
        return;
    parsing_links_destroy(links->next);
    free(links->data);
    free(links);
}
