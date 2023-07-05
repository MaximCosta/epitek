/*
** EPITECH PROJECT, 2022
** corewar [WSL: Ubuntu]
** File description:
** cycle2
*/

#include "../../include/corewar.h"

int next_cycle_part2(corewar_t *corewar, process_t *process, vm_t *vm)
{
    while (process) {
        do_process(corewar, process);
        process = process->next;
    }
    vm->cycles++;
    vm->lastcheck++;
}
