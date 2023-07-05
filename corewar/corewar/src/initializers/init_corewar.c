/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../include/corewar.h"

corewar_t *init_corewar(int ac, char **argv)
{
    corewar_t *corewar = (corewar_t *)my_calloc(sizeof(corewar_t));

    corewar->vm = init_vm();
    corewar->vm->check_interval = CYCLE_TO_DIE;
    load_champions(corewar, ac, argv);
    return corewar;
}

void destroy_champions(list_t *list)
{
    if (!list)
        return;
    destroy_champions(list->next);
    free(list->value);
}

int destroy_corewar(corewar_t *corewar)
{
    destroy_vm(corewar->vm);
    destroy_champions(corewar->champions);
    free(corewar);
    return 84;
}
