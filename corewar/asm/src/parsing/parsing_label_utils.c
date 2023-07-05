/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../include/asm.h"

bool is_label_char(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    if (c >= 'A' && c <= 'Z')
        return true;
    if (c >= '0' && c <= '9')
        return true;
    if (c == '_' || c == ':')
        return true;
    return false;
}

bool already_exist_label(list_t *labels, char *label)
{
    list_t *tmp = labels;

    while (tmp) {
        if (my_strcmp(((label_t *) tmp->value)->name, label) == 0)
            return true;
        tmp = tmp->next;
    }
    return false;
}

bool is_valid_label_name(char *label)
{
    if (!label)
        return false;
    for (int i = 1; label[i]; i++) {
        if (!is_label_char(label[i]))
            return false;
    }
    return true;
}

int get_label_offset(list_t **labels, char *label)
{
    int res = 0;
    list_t *labelt = *labels;

    while (labelt) {
        if (my_strcmp(((label_t *) labelt->value)->name, label) == 0)
            return ((label_t *) labelt->value)->offset;
        labelt = labelt->next;
    }
    return res;
}
