/*
** EPITECH PROJECT, 2021
** Bistro-matic
** File description:
** eval_expr
*/

#include <stdlib.h>
#include "bistromatic.h"

void check_op(char c, int *check, char const *ops, char const *base)
{
    int err = 1;

    for (int i = 1; i <= check[0]; i++) {
        if (c == ops[check[i]])
            err = 0;
    }
    if (char_in_str(c, (char*) base))
        err = 0;
    if (err == 1)
        exit(my_putstr_err(SYNTAX_ERROR_MSG, EXIT_USAGE));
}

void check_ops_in_expr(char const *base, char const *ops,
    char const *expr, unsigned int size)
{
    for (unsigned int i = 0; i < size - 1; i++) {
        if (expr[i] == ops[OP_PLUS] || expr[i] == ops[OP_NEG])
            check_op(expr[i + 1], (int*) MIN_PLUS, ops, base);
        if (expr[i] == ops[OP_MULT] || expr[i] == ops[OP_DIV]
            || expr[i] == ops[OP_MOD])
            check_op(expr[i + 1] , (int*) FACTOR, ops, base);
        if (expr[i] == ops[OP_OPEN_PARENT])
            check_op(expr[i + 1], (int*) OPEN, ops, base);
    }
}

char *eval_expr(char const *base, char const *ops,
    char const *expr, unsigned int size)
{
    opbase_t opbase;
    char *res;

    check_base_ops(base);
    check_base_ops(ops);
    check_ops_in_base(ops, base);
    check_syntax(base, ops, expr, size);
    check_parent(ops, expr, size);
    check_nb_parent(ops, expr, size);
    check_ops_in_expr(base, ops, expr, size);
    opbase.base = base;
    opbase.ops = ops;
    opbase.list = malloc(sizeof(linked_list_t*));
    *opbase.list = NULL;
    res = my_strdup(parse_expressions((char**) &expr, opbase));
    free_gc(opbase.list);
    free(opbase.list);
    return res;
}
