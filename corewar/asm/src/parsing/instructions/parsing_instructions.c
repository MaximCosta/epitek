/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../../include/asm.h"

static int handle_params_two(
    parsing_t *parsing, int mnemonique_index, args_type_t parameter_type)
{
    if (parameter_type == T_REG) {
        increment_prog_size(parsing, 1);
        return 1;
    }
    if (parameter_type == T_DIR) {
        increment_prog_size(
            parsing, op_tab[mnemonique_index].directsize == 32 ? 4 : 2);
        return 1;
    }
    if (parameter_type == T_IND) {
        increment_prog_size(parsing, 2);
        return 1;
    }
    return 0;
}

static void handle_params(
    parsing_t *parsing, int mnemonique_index, char **splitted)
{
    int parameter_type = T_NONE;

    increment_prog_size(parsing, 1);
    increment_prog_size(parsing, op_tab[mnemonique_index].has_pcb);
    if (count_2d_array_size(splitted) - 1 !=
        op_tab[mnemonique_index].nbr_args)
        exit(84);
    for (int i = 1; i <= op_tab[mnemonique_index].nbr_args; i++) {
        parameter_type = get_param_type(parsing, rstrip(lstrip(splitted[i])));
        exit_if_condition(parameter_type == T_NONE, 84);
        exit_if_condition(
            !can_be_param_type(
                op_tab[mnemonique_index].type[i - 1], parameter_type),
            84);
        if (handle_params_two(parsing, mnemonique_index, parameter_type))
            continue;
    }
}

void set_label_offset(parsing_t *parsing, char *label, int offset)
{
    list_t *tmp = parsing->labels;

    while (tmp) {
        if (my_strcmp(((label_t *) tmp->value)->name, label) == 0) {
            ((label_t *) tmp->value)->offset = offset;
            return;
        }
        tmp = tmp->next;
    }
}

static void handle_label_declaration(
    parsing_t *parsing, char *label_s, char *next)
{
    int mnemonique_index = -1;
    char **splitted = 0;

    set_label_offset(parsing, label_s, parsing->prog_size);
    if (my_strlen(next) == 1 && next[0] == ':')
        return;
    splitted = split(next + 1, " ,\t");
    mnemonique_index = get_mnemonique_index(splitted[0]);
    if (splitted[0] && mnemonique_index == -1)
        exit(84);
    handle_params(parsing, mnemonique_index, splitted);
}

void first_handle_instruction_line(char *line, parsing_t *parsing)
{
    char **splitted = split(line, " ,\t");
    int mnemonique_index = -1;

    if (has_multiple_operation(line))
        exit(84);
    exit_if_condition(!parsing->has_name, 84);
    if (!splitted)
        return;
    mnemonique_index = get_mnemonique_index(splitted[0]);
    exit_if_condition(
        mnemonique_index == -1 && !is_label_declaration(splitted[0]), 84);
    exit_if_condition(count_2d_array_size(split(line, ",")) > 3, 84);
    if (is_label_declaration(splitted[0])) {
        exit_if_condition(!is_valid_label_name(splitted[0]), 84);
        handle_label_declaration(parsing, split(line, ":")[0],
            lstrip(rstrip(line + my_strlen(split(line, ":")[0]))));
        return;
    }
    handle_params(parsing, mnemonique_index, splitted);
}
