/*
** EPITECH PROJECT, 2021
** Day08
** File description:
** Task01 - MY_STRDUP
*/

#include "../../../include/engine/engine.h"

gc_t glob_gc = { 0 };

void gc_destroy(void) __attribute__((destructor));

void *gc_malloc(size_t __size)
{
    void *ptr = malloc(__size);

    list_insert_first(&glob_gc.ptrs, ptr);
    return ptr;
}

void gc_destroy(void)
{
    list_t *ptrs = glob_gc.ptrs;
    list_t *tmp = 0;

    while (ptrs) {
        free(ptrs->value);
        tmp = ptrs;
        ptrs = ptrs->next;
        free(tmp);
    }
}
