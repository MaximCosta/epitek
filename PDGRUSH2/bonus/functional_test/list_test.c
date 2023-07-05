/*
** EPITECH PROJECT, 2021
** player_test.c
** File description:
** Player Tests
*/

#include "../../int.h"
#include "../../list.h"
#include "../../new.h"

int main(void)
{
    Object *list = new (List, 10, Int, 0);
    Object *it = begin(list);
    Object *it_end = end(list);

    printf("list size: %zu\n", len(list));
    setitem(list, 5, 12);
    setitem(list, 6, 13);
    while (getval(it) != NULL) {
        printf("%s\n", str(getval(it)));
        incr(it);
    }
    delete (it);
    delete (it_end);
    delete (list);
}
