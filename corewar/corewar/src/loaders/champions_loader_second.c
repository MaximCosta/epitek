/*
** EPITECH PROJECT, 2022
** corewar [WSL: Ubuntu]
** File description:
** champions_loader_
*/

#include "../../include/corewar.h"

void exit_number(int number, corewar_t *corewar)
{
    if (number == 0)
        exit(destroy_corewar(corewar));
}

void exit_champ(read_champ_t *champ, corewar_t *corewar)
{
    if (!champ)
        exit(destroy_corewar(corewar));
}

void free_champ(read_champ_t *champ)
{
    free(champ->field);
    free(champ);
}

int get_real_value(int value)
{
    while (value < 0)
        value += MEM_SIZE;
    return value % MEM_SIZE;
}

void place_in_arena(corewar_t *corewar, champion_t *champion,
                    read_champ_t *champ, int args[2])
{
    int tmp = get_real_value(args[1] * args[0] + champion->padding);

    process_append(corewar->vm, create_process(champion->id, tmp));
    for (int j = 0; j < champion->prog_size; j++) {
        tmp = get_real_value(args[0] * args[1] + j + champion->padding);
        if (corewar->vm->fields[tmp].value != 0)
            exit(destroy_corewar(corewar));
        corewar->vm->fields[tmp].value = champ->field[j].value;
        corewar->vm->fields[tmp].owner_id = champion->id;
    }
}
