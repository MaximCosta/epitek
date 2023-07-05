/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** create_process.c
*/

#include "../../../include/corewar.h"

process_t *create_process(int id, int pos)
{
    process_t *process = (process_t *) my_calloc(sizeof(process_t));

    process->pos = pos;
    process->cycle = 0;
    process->live = 0;
    process->carry = 0;
    process->registries[0] = id;
    return process;
}

process_t *clone_process(process_t *process, int new_pos)
{
    process_t *clone = (process_t *) my_calloc(sizeof(process_t));

    clone->pos = new_pos;
    clone->carry = process->carry;
    for (int i = 0; i < REG_NUMBER; i++)
        clone->registries[i] = process->registries[i];
    return clone;
}

void process_append(vm_t *vm, process_t *process)
{
    process_t *last = vm->processes;

    if (!last) {
        vm->processes = process;
        return;
    }
    while (last->next)
        last = last->next;
    last->next = process;
}
