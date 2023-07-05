/*
** EPITECH PROJECT, 2021
** player_test.c
** File description:
** Player Tests
*/

#include "../../array.h"
#include "../../new.h"
#include "../../int.h"

int main(void)
{
    Object *array = new (Array, 10, Int, 2);
    Object *it = begin(array);
    Object *it_end = end(array);

    printf("array size: %zu\n", len(array));
    setitem(array, 5, 12);
    setitem(array, 6, 13);
    while (lt(it, it_end)) {
        printf("%s\n", str(getval(it)));
        incr(it);
    }
    delete (it);
    delete (it_end);
    delete (array);
}
