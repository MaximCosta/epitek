/*
** EPITECH PROJECT, 2021
** eval_expr
** File description:
** eval
*/

#include <unistd.h>
#include "include/my.h"
#include "include/eval_expr.h"

int get_op(char op, int nbr, int next_nbr)
{
    switch (op) {
        case '/':
            return nbr / next_nbr;
        case '(':
            return nbr * next_nbr;
        case '*':
            return nbr * next_nbr;
        default:
            return nbr % next_nbr;
    }
}

int number(char const **expr)
{
    int nbr;

    if (**expr == '(') {
        (*expr)++;
        nbr = my_sum(expr);
        if (**expr == ')') 
            (*expr)++;
        return nbr;
    }
    return my_strtol((char**)expr);
}

int my_factors(char const **expr)
{
    int nbr = number(expr);
    int next_nbr;
    char op;

    while (**expr) {
        op = **expr;
        if (FAC(op)) return nbr;
        (*expr)++;
        next_nbr = (op == '(' || **expr == '-' ? my_sum(expr) : number(expr));
        nbr = get_op(op, nbr, next_nbr);
    }
    return nbr;
}

int my_sum(char const **expr)
{
    int nbr = my_factors(expr);
    int next_nbr;
    char op;

    while (**expr) {
        op = **expr;
        if (ADD(op))
            return (nbr);
        (*expr)++;
        next_nbr = my_factors(expr);
        if (op == '+')
            nbr += next_nbr;
        else
            nbr -= next_nbr;
    }
    return nbr;
}

int eval_expr(char const *expr)
{
    return my_sum(&expr);
}
