/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** returns a number, sent as string
*/

#include "../push.h"

static int check_nb(char *str, int ps)
{
    long int rs = 0;
    long int tmp = 0;

    while (*str >= 48 && *str <= 57) {
        tmp = rs * 10;
        tmp += *str - 48;
        if (ps == 1 && tmp > 2147483647)
            return 0;
        if (ps == -1 && tmp > 2147483648)
            return 0;
        rs = tmp;
        str++;
    }
    return (int)(rs * ps);
}

void delete_last_node(linkedlist_t **list)
{
    linkedlist_t *tmp;
    linkedlist_t *back;

    if (*list == NULL) return;
    if ((*list)->next == NULL) {
        *list = NULL;
    } else {
        tmp = *list;
        for (;tmp->next->next != NULL; tmp = tmp->next);
        back = tmp->next;
        tmp->next = NULL;
        free(back);
    }
}

void sa(linkedlist_t *list_a)
{
    linkedlist_t* temp = list_a;

    if (temp != NULL && temp->next != NULL) {
        swap(&temp->data, &temp->next->data);
        temp = temp->next->next;
    }
}

int my_getnbr(char *str)
{
    int ps = 1;

    while (('-' == (*str)) || ((*str) == '+')) {
        if (*str == '-')
            ps = ps * -1;
        str++;
    }
    return check_nb(str, ps);
}
