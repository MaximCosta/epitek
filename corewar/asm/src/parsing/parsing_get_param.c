/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../include/asm.h"

int get_param_type_two(parsing_t *parsing, char *str)
{
    if (str[0] == ':') {
        if (!already_exist_label(parsing->labels, str + 1))
            return T_NONE;
        return T_IND;
    }
    while (*str) {
        if ((*str < '0' || *str > '9') && *str != '-')
            return T_NONE;
        str++;
    }
    return T_IND;
}

int get_param_type_one(parsing_t *parsing, char *str)
{
    if (str[1] && str[1] == ':') {
        if (!already_exist_label(parsing->labels, str + 2))
            return T_NONE;
        return -1;
    }
    str++;
    while (*str) {
        if ((*str < '0' || *str > '9') && *str != '-')
            return T_NONE;
        str++;
    }
    return -1;
}

int get_param_type(parsing_t *parsing, char *str)
{
    if (!str || (str[0] == '%' && my_strlen(str) == 1))
        return T_NONE;
    if (str[0] == '%') {
        if (get_param_type_one(parsing, str) == T_NONE)
            return T_NONE;
        return T_DIR;
    }
    if (str[0] == 'r') {
        if (!str_contains_only_number(str + 1))
            return T_NONE;
        if (my_getnbr(str + 1) > REG_NUMBER || my_getnbr(str + 1) < 1)
            return T_NONE;
        return T_REG;
    }
    return get_param_type_two(parsing, str);
}
