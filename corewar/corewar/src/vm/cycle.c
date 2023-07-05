/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** cycle.c
*/

#include "../../include/corewar.h"

static const void (*f[16])(corewar_t *corewar, instruction_t *instruction,
    process_t *process) = {&live_instruction, &ld_instruction, &st_instruction,
    &add_instruction, &sub_instruction, &and_instruction, &or_instruction,
    &xor_instruction, &zjmp_instruction, &ldi_instruction, &sti_instruction,
    &fork_instruction, &lld_instruction, &lldi_instruction, &lfork_instruction,
    &aff_instruction};

int check_if_lived(corewar_t *corewar)
{
    vm_t *vm = corewar->vm;
    int nb_live = 0;
    int tmp = 0;

    for (int i = 0; i < 4; i++) {
        if (vm->alives[i]) {
            tmp = i;
            nb_live++;
        }
        vm->alives[i] = 0;
    }
    if (nb_live > 1 || nb_live == 0)
        return 1;
    if (nb_live == 1)
        my_printf("The player %d(%s)has won.\n", tmp + 1,
            get_champion_name(corewar, tmp + 1));
    vm->is_winner = tmp + 1;
    return 0;
}

void do_action(corewar_t *corewar, process_t *process)
{
    process->cycle--;
    if (process->cycle)
        return;
    f[process->instruction->opcode - 1](
        corewar, process->instruction, process);
    process->cycle = 0;
    free(process->instruction);
    process->instruction = NULL;
}

void do_process(corewar_t *corewar, process_t *process)
{
    if (process->instruction)
        return do_action(corewar, process);
    process->instruction = get_instruction(corewar->vm->fields, process->pos);
    if (!process->instruction) {
        process->pos = (process->pos + 1) % MEM_SIZE;
        return;
    }
    process->cycle = op_tab[process->instruction->opcode - 1].nbr_cycles;
    do_action(corewar, process);
}

void next_cycle(corewar_t *corewar)
{
    vm_t *vm = corewar->vm;
    process_t *process = vm->processes;

    if (vm->dump_time == vm->cycles)
        dump_memory(corewar);
    if (vm->lastcheck >= vm->check_interval) {
        vm->lastcheck = 0;
        vm->check_interval -= CYCLE_DELTA;
        if (!check_if_lived(corewar))
            return;
        if (vm->check_interval <= 0) {
            vm->is_winner = -1;
            my_printf("No live remaining, and no winner has been decided.\n");
            return;
        }
    }
    next_cycle_part2(corewar, process, vm);
}
