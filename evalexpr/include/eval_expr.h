/*
** EPITECH PROJECT, 2021
** include/eval_expr
** File description:
** header de hader
*/

#define ADD(x) (x != '+' && x != '-')
#define FAC(x) (x != '/' && x != '*' && x != '%' && x != '(')

int get_op(char op, int nbr, int nbr2);
int number(char const **expr);
int my_factors(char const **expr);
int my_sum(char const **expr);
int eval_expr(char const* expr);
