/*
** EPITECH PROJECT, 2021
** include/bistro
** File description:
** C-x C-c
*/

#define NUM(x) (x - '0')
#define ASC(x) (x + '0')

typedef struct {
    char *val1;
    char *val2;
    int len1;
    int len2;
    int sig1;
    int sig2;
    char *res;
} nb_info;

int getter_sum(nb_info nb, int i1, int i2);
int getter_neg(nb_info nb, int i1, int i2, int re);
void sum(nb_info nb);
void neg(nb_info nb);