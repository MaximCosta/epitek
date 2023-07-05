/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef LIST_H
    #define LIST_H

typedef struct s_list list_t;

struct s_list {

    list_t *next;
    void *value;

};

list_t *list_create_node(void *value);

void list_insert_first(list_t **node, void *value);

list_t *list_insert_end(list_t **node, void *value);

void list_delete(list_t **node);

void list_delete_node(list_t *node);

void list_delete_first_node(list_t **list);

void list_delete_last_node(list_t **list);

int list_size(list_t *node);

void list_remove(list_t **list, void *value);

#endif //LIST_H
