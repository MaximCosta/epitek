/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/

#include "../../include/corewar.h"

vm_t *init_vm(void)
{
    vm_t *vm = (vm_t *) my_calloc(sizeof(vm_t));

    return vm;
}

void destroy_vm(vm_t *vm)
{
    free(vm);
}
