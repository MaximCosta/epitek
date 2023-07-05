/*
** EPITECH PROJECT, 2021
** Bistro-matic
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistromatic.h"

static int my_atoi(char const *str)
{
    return my_getnbr(str);
}

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr_err(SYNTAX_ERROR_MSG, EXIT_SIZE_NEG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr_err(ERROR_MSG, EXIT_MALLOC);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr_err(ERROR_MSG, EXIT_READ);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

static void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr_err(SYNTAX_ERROR_MSG, EXIT_OPS);
        exit(EXIT_OPS);
    }
}

static void check_base(char const *b)
{
    if (my_strlen(b) < 2) {
        my_putstr_err(SYNTAX_ERROR_MSG, EXIT_BASE);
        exit(EXIT_BASE);
    }
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr = NULL;
    char *res = NULL;

    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+_*/%\" exp_len\n");
        return (EXIT_USAGE);
    }
    check_base(av[1]);
    check_ops(av[2]);
    size = my_atoi(av[3]);
    expr = get_expr(size);
    res = eval_expr(av[1], av[2], expr, size);
    my_putstr(res);
    free(res);
    free(expr);
    return (EXIT_SUCCESS);
}
