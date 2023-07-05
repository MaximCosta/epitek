/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef GC_H
    #define GC_H
    #include "list/list.h"
    #include "stdlib.h"
typedef struct s_gc gc_t;
extern gc_t glob_gc;
struct s_gc {
    list_t *ptrs;
};

void *gc_malloc(size_t __size);
void gc_destroy(void);

#endif // GC_H
