/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../include/corewar.h"

START_FUNC_DEF

void start_corewar(corewar_t *corewar)
{
    vm_t *vm = corewar->vm;
    instruction_t *instrution = get_instruction(vm->fields, 0);

    while (!vm->is_winner)
        next_cycle(corewar);
}

int main(int argc, char **argv)
{
    corewar_t *corewar = init_corewar(argc, argv);
    int *n = (int *) my_calloc(sizeof(int));

    START_FUNC
    destroy_corewar(corewar);
    return 0;
}
