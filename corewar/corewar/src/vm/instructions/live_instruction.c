/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** cycle.c
*/

#include "../../../include/corewar.h"

char *get_champion_name(corewar_t *corewar, int id)
{
    list_t *champions = corewar->champions;
    champion_t *champion = NULL;

    while (champions) {
        champion = champions->value;
        if (champion->id == id)
            return champion->name;
        champions = champions->next;
    }
    return NULL;
}

void live_instruction(
    corewar_t *corewar, instruction_t *instruction, process_t *process)
{
    char *name = get_champion_name(corewar, instruction->params[0] + 1);

    if (!name)
        return move_pc(process, instruction->size);;
    my_printf("The player %d(%s)is alive.\n",
            instruction->params[0] + 1,
            get_champion_name(corewar, instruction->params[0] + 1)
    );
    corewar->vm->alives[instruction->params[0]] = 1;
    move_pc(process, instruction->size);
}
