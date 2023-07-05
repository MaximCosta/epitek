/*
** EPITECH PROJECT, 2021
** my_ls [WSL: Ubuntu]
** File description:
** lc_sort
*/

#include "my.h"
#include <stdlib.h>

static void lc_swap(linkedlist_t *a, linkedlist_t *b)
{
    void *temp = a->data;

    a->data = b->data;
    b->data = temp;
}

void lc_sort(linkedlist_t *list, int (*cmp)(), int ref)
{
    int swapped;
    linkedlist_t *ptr1;
    linkedlist_t *lptr = NULL;

    if (list == NULL) return;
    do {
        swapped = 0;
        ptr1 = list;
        while (ptr1->next != lptr) {
            if ((*cmp)(ptr1->data > ptr1->next->data) > ref) {
                lc_swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
