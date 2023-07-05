/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-lemin-flavio.moreno
** File description:
** do_parsing_loop.c
*/

#include "my.h"
#include "parsing.h"

parsing_t *do_parsing_verify(parsing_t *parsing)
{
    if (!parsing->start || !parsing->end)
        return parsing_destroy(parsing);
    return parsing;
}
