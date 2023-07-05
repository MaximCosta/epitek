/*
** EPITECH PROJECT, 2021
** Pool Day11
** File description:
** mylist
*/

#ifndef MYLIST_H
    #define MYLIST_H
typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;
void create_node(linked_list_t **head, void *);
void my_add_in_sorted_list(linked_list_t **, void *, int (*cmp)());
int my_apply_on_matching_nodes(linked_list_t *,
    int (*f)(), void const *, int (*cmp)());
int my_apply_on_nodes(linked_list_t *, int (*f)(void *));
void my_concat_list(linked_list_t **, linked_list_t *);
int my_delete_nodes(linked_list_t **, void const *, int (*cmp)());
linked_list_t *my_find_node(linked_list_t const *, void const *, int (*cmp)());
int my_list_size(linked_list_t const *);
void my_merge(linked_list_t **, linked_list_t *, int (*cmp)());
linked_list_t *my_params_to_list(int, char * const *);
void my_rev_list(linked_list_t **);
void my_sort_list(linked_list_t **, int (*cmp)());
#endif /* !MYLIST_H */
