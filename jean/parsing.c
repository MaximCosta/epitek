/*
** EPITECH PROJECT, 2021
** EvalExpr
** File description:
** parsing
*/

#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

static char *branch_parse_factor(char **str, opbase_t opbase)
{
    char *val = NULL;
    int sign = 0;

    sign = get_sign(str, opbase);
    if (sign == -1) {
        val = do_sub(zero(opbase), parse_expressions(str, opbase), opbase);
        *str += 1;
    } else if (sign == 1) {
        val = parse_expressions(str, opbase);
        *str += 1;
    } else
        val = get_infin_nbr(str, opbase);
    return val;
}

static char *parse_factors(char **str, opbase_t opbase)
{
    char *val = NULL;

    if (**str == opbase.ops[OP_OPEN_PARENT]) {
        *str += 1;
        val = parse_expressions(str, opbase);
        *str += 1;
        return val;
    } else if (**str == opbase.ops[OP_SUB]) {
        val = branch_parse_factor(str, opbase);
    } else
        val = get_infin_nbr(str, opbase);
    return val;
}

static char *parse_terms(char **str, opbase_t opbase)
{
    char *val = parse_factors(str, opbase);

    while (**str == opbase.ops[OP_MULT] || **str == opbase.ops[OP_DIV]
        || **str == opbase.ops[OP_MOD]) {
        if (**str == opbase.ops[OP_MULT]) {
            *str += 1;
            val = do_mul(val, parse_factors(str, opbase), opbase);
        } else if (**str == opbase.ops[OP_DIV]) {
            *str += 1;
            val = do_div(val, parse_factors(str, opbase), opbase);
        } else {
            *str += 1;
            val = do_mod(val, parse_factors(str, opbase), opbase);
        }
    }
    return val;
}

char *parse_expressions(char **str, opbase_t opbase)
{
    char *val = parse_terms(str, opbase);

    while (**str == opbase.ops[OP_PLUS] || **str == opbase.ops[OP_SUB]) {
        if (**str == opbase.ops[OP_PLUS]) {
            *str += 1;
            val = do_add(val, parse_terms(str, opbase), opbase);
        } else {
            *str += 1;
            val = do_sub(val, parse_terms(str, opbase), opbase);
        }
    }
    return val;
}
