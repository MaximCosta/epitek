/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** cycle.c
*/

#include "../../../include/corewar.h"

void st_instruction(
    corewar_t *corewar, instruction_t *instruction, process_t *process)
{
    if (instruction->params_type[1] == T_REG) {
        process->registries[instruction->params[1] - 1] =
            process->registries[instruction->params[0]];
    } else {
        write_at_pos(corewar->vm->fields,
            process->registries[instruction->params[0] - 1],
            process->pos +
            instruction->params[1] % IDX_MOD,
            process->registries[0]);
    }
    move_pc(process, instruction->size);
}
