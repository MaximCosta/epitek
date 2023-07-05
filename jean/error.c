/*
** EPITECH PROJECT, 2021
** bistro-matic
** File description:
** error
*/

#include <stdlib.h>
#include "bistromatic.h"

void check_ops_in_base(char const *ops, char const *base)
{
    for (int i = 0; i < my_strlen(ops); i++) {
        if (char_in_str(ops[i], (char*) base)) {
            exit(my_putstr_err(SYNTAX_ERROR_MSG, EXIT_USAGE));
        }
    }
}

void check_base_ops(char const *base)
{
    for (int i = 0; i < my_strlen(base); i++) {
        if (char_in_str(base[i], (char*) base + i + 1)) {
            exit(my_putstr_err(SYNTAX_ERROR_MSG, EXIT_USAGE));
        }
    }
}

void check_syntax(char const *base, char const *ops,
    char const *expr, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++) {
        if (!char_in_str(expr[i], (char*) base)
                && !char_in_str(expr[i], (char*) ops))
            exit(my_putstr_err(SYNTAX_ERROR_MSG, EXIT_USAGE));
    }
}

void check_parent(char const *ops, char const *expr, unsigned int size)
{
    int cpt = 0;

    for (unsigned int i = 0; i < size; i++) {
        if (expr[i] == ops[OP_OPEN_PARENT])
            cpt++;
        else if (expr[i] == ops[OP_CLOSE_PARENT])
            cpt--;
        if (cpt < 0) {
            exit(my_putstr_err(SYNTAX_ERROR_MSG, EXIT_USAGE));
        }
    }
    if (cpt != 0)
        exit(my_putstr_err(SYNTAX_ERROR_MSG, EXIT_USAGE));
}

void check_nb_parent(char const *ops, char const *expr, unsigned int size)
{
    int error = 0;

    for (unsigned int i = 0; i < size - 1; i++) {
        if (expr[i + 1] == ops[OP_OPEN_PARENT]
                && !char_in_str(expr[i], (char*) ops))
            error = 1;
        if (expr[i] == ops[OP_CLOSE_PARENT]
                && !char_in_str(expr[i + 1], (char*) ops))
            error = 1;
        if (error == 1) {;
            exit(my_putstr_err(SYNTAX_ERROR_MSG, EXIT_USAGE));
        }
    }
}
