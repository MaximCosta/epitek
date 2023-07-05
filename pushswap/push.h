/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-maxim.costa [WSL: Ubuntu]
** File description:
** push
*/

#ifndef PUSH_H_
#define PUSH_H_
#include <unistd.h>
#include <stdlib.h>
typedef struct linkedlist_s {
    int data;
    struct linkedlist_s *next;
} linkedlist_t;
linkedlist_t *create_node(int value);
void add_node_at_back(int data, linkedlist_t **node);
void add_node_at_front(int data, linkedlist_t **node);
void delete_first_node(linkedlist_t **list);
void delete_last_node(linkedlist_t **list);
void sa(linkedlist_t *list_a);
int my_getnbr(char *str);
void swap(int *a, int *b);
void ra(linkedlist_t **list_a, int k);
#endif /* !PUSH_H_ */
