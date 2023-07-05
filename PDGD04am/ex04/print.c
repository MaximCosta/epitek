/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD04am-maxim.costa [WSL: Ubuntu]
** File description:
** print
*/

#include "print.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    int i;
    for (i = strlen(str) - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    putchar('\n');
}

void print_upper(const char *str)
{
    int i;
    for (i = 0; str[i]; i++) {
        putchar(toupper(str[i]));
    }
    putchar('\n');
}

void print_42(const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*print_functions[4])(const char *) = {
        &print_normal, &print_reverse, &print_upper, &print_42};
    (*print_functions[action])(str);
}
