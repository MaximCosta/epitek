/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-kilyan.cotten
** File description:
** parse.c
*/

#include "mysh.h"

void get_redirection_quote(parse_t *p)
{

}

void get_redirection_arrow(parse_t *p)
{
    if (p->line[p->i] != p->the_char) {
        if (p->in)
            p->in = 0;
        (*p->cmd)[p->k++] = p->line[p->i];
        return;
    }
    if (p->d <= 0) {
        if (!p->j)
            p->error = MISSING_NAME;
        else
            p->error = p->the_char == '>' ? AMBIGOUS_OUTPUT : AMBIGOUS_INPUT;
    }
    if (p->j && !p->in)
        p->error = p->the_char == '>' ? AMBIGOUS_OUTPUT : AMBIGOUS_INPUT;
    p->in = 1;
    p->d--;
}

int get_redirection_space(parse_t *p)
{
    if (!p->in)
        return 0;
    if (p->in && p->d) {
        p->in = 0;
        p->d = p->d_base;
        return 0;
    }
    if (p->j) {
        p->in = 0;
    } else if (p->in) {
        return 1;
    }
    return 0;
}

void get_redirection_char(parse_t *p)
{
    if (p->in && p->d) {
        p->d = p->d_base;
        p->in = 0;
    }
    if (p->in && !p->d)
        (*p->file)[p->j++] = p->line[p->i];
    else
        (*p->cmd)[p->k++] = p->line[p->i];
}

int get_redirection(char *line, char **file, char **cmd, int *d)
{
    parse_t p = {line, file, cmd, 0, 0, 0, 0, d[0], d[1], 0, 0, 0, d[1]};

    *p.cmd = my_calloc(my_strlen(p.line) * sizeof(char));
    *p.file = my_calloc(1024 * sizeof(char));
    for (p.i = 0; p.line[p.i] && !p.error; p.i++) {
        if (p.line[p.i] == '"' || p.line[p.i] == '\'') {
            get_redirection_quote(&p);
            continue;
        }
        if (p.line[p.i] == '>' || p.line[p.i] == '<') {
            get_redirection_arrow(&p);
            continue;
        }
        if (!((p.line[p.i] == ' ' || p.line[p.i] == '\t') &&
            get_redirection_space(&p)))
            get_redirection_char(&p);
    }
    return p.in && !p.j ? MISSING_NAME : p.error;
}
