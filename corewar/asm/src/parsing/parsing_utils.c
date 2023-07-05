/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../include/asm.h"

int get_mnemonique_index(char *str)
{
    int i = 0;

    if (!str)
        return -1;
    while (op_tab[i].mnemonique) {
        if (my_strcmp(op_tab[i].mnemonique, str) == 0)
            return i;
        i++;
    }
    return -1;
}

void increment_prog_size(parsing_t *parsing, int len)
{
    parsing->prog_size += len;
}

bool can_be_param_type(args_type_t types, args_type_t type)
{
    if (types % 2 != 0 && type == T_REG)
        return true;
    if ((types == 7 || types == 6 || types == 3 || types == 2)
        && type == T_DIR)
        return true;
    if ((types == 7 || types == 5 || types == 6 || types == 4)
        && type == T_IND)
        return true;
    return false;
}

bool is_label_declaration(char *str)
{
    while (*str) {
        if (*str == LABEL_CHAR)
            return true;
        str++;
    }
    return false;
}
