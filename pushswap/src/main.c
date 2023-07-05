/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-maxim.costa [WSL: Ubuntu]
** File description:
** main
*/

#include "../push.h"

void swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

void ra(linkedlist_t **list_a, int k)
{
    linkedlist_t* current;
    linkedlist_t* kth_node;

    if (k == 0) return;
    current = *list_a;
    for (int count = 1; count < k && current != NULL; count++)
        current = current->next;
    if (current == NULL) return;
    kth_node = current;
    for (;current->next != NULL; current = current->next);
    current->next = *list_a;
    *list_a = kth_node->next;
    kth_node->next = NULL;
}

int main(int argc, char **argv)
{
    linkedlist_t *list = malloc(sizeof(linkedlist_t));
    linkedlist_t *tmp;
    int sorted = 1;
    int old = -2147483648;

    if (argc < 2) exit(84);
    list->data = my_getnbr(argv[1]);
    list->next = NULL;
    for (int i = 2; i < argc; i++)
        add_node_at_back(my_getnbr(argv[i]), &list);
    for (tmp = list; tmp != NULL && sorted == 1; tmp = tmp->next) {
        if (tmp->data < old)
            sorted = 0;
        old = tmp->data;
    }
    if (sorted) write(1,"\n",1);
    else write(1,"ra",2);
}
