/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** cycle.c
*/

#include "../../../include/corewar.h"

void fork_instruction(
    corewar_t *corewar, instruction_t *instruction, process_t *process)
{
    int tmp = 0;

    if (!process->carry) {
        move_pc(process, instruction->size);
        return;
    }
    tmp = (process->pos + process->registries[0] % IDX_MOD) % MEM_SIZE;
    process_append(corewar->vm, clone_process(process, tmp));
    move_pc(process, instruction->size);
}
