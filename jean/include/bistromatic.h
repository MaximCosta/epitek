/*
** EPITECH PROJECT, 2021
** Bistro-matic
** File description:
** bistromatic
*/

#ifndef BISTROMATIC_H
    #define BISTROMATIC_H
    #define POSITIF         0
    #define NEGATIF         1
    #define OP_OPEN_PARENT  0
    #define OP_CLOSE_PARENT 1
    #define OP_PLUS         2
    #define OP_SUB          3
    #define OP_NEG          3
    #define OP_MULT         4
    #define OP_DIV          5
    #define OP_MOD          6
    #define DIGIT           -1
    #define EXIT_USAGE      84
    #define EXIT_BASE       84
    #define EXIT_SIZE_NEG   84
    #define EXIT_MALLOC     84
    #define EXIT_READ       84
    #define EXIT_OPS        84
    #define SYNTAX_ERROR_MSG "syntax error"
    #define ERROR_MSG        "error"
    #include "my.h"
    #include "mylist.h"
typedef struct calcul {
    char *nb1;
    int len1;
    char *nb2;
    int len2;
    char *res;
    int len_res;
} calc;
typedef struct cal_mult {
    char *u;
    char *v;
    char *w;
} cal_mul;
typedef struct convert {
    char *nbr;
    int len_nbr;
    int len;
} convert_t;
typedef struct data_convert {
    char *b_from;
    char *b_to;
    char *size;
} data_convert_t;
typedef struct opbase {
    char const *base;
    char const *ops;
    linked_list_t **list;
} opbase_t;
char *eval_expr(char const *, char const *, char const *, unsigned int);
char *parse_expressions(char **str, opbase_t opbase);
char *get_infin_nbr(char **src, opbase_t opbase);
int neg_numbers(char **nb1, char **nb2, opbase_t opbase);
char *do_add(char *nb1, char *nb2, opbase_t opbase);
char *do_sub(char *nb1, char *nb2, opbase_t opbase);
char *do_mul(char *nb1, char *nb2, opbase_t opbase);
char *do_div(char *nb1, char *nb2, opbase_t opbase);
char *do_mod(char *nb1, char *nb2, opbase_t opbase);
char *infin_add(char *nb1, char *nb2, int neg, opbase_t opbase);
char *infin_sub(char *nb1, char *nb2, opbase_t opbase);
char *infin_mul(char *nb1, char *nb2, int neg, opbase_t opbase);
char *infin_div(char *nb1, char *nb2, int neg, opbase_t opbase);
char *infin_mod(char *nb1, char *nb2, int neg, opbase_t opbase);
int nb_cmp(calc cal, char const *base);
void my_strncpy_nbr(char *dest, char const *src, int n, opbase_t opbase);
char *append_zero(char const *str, int nb, opbase_t opbase);
int is_in_base(char c, char const *base);
int index_base(char const *base, char c);
char *zero(opbase_t opbase);
void check_ops_in_base(char const *ops, char const *base);
void check_base_ops(char const *base);
void check_syntax(char const *, char const *, char const *, unsigned int size);
void check_parent(char const *ops, char const *expr, unsigned int size);
void check_nb_parent(char const *ops, char const *expr, unsigned int size);
char *litlle_number(char c, opbase_t opbase);
int my_strcmp_base(char *nb1, char *nb2, char const *base);
char *convert_base(char const *, char const *, char const *, opbase_t);
void free_gc(linked_list_t **list);
char *get(char *val, opbase_t opbase);
int get_sign(char **str, opbase_t opbase);
static const int MIN_PLUS[] = {3, OP_NEG, OP_PLUS, OP_OPEN_PARENT};
static const int FACTOR[] = {2, OP_NEG, OP_OPEN_PARENT};
static const int OPEN[] = {2, OP_NEG, OP_OPEN_PARENT};
#endif /* !BISTROMATIC_H */
