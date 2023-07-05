/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD05-maxim.costa [WSL: Ubuntu]
** File description:
** string
*/

#include "string.h"

void string_init(string_t *this, const char *s)
{
    this->str = strdup(s);
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_c = &append_c;
    this->append_s = &append_s;
    this->at = &func_at;
    this->clear = &clear;
    this->length = &length;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
}

void string_destroy(string_t *this)
{
    if (this->str)
        free(this->str);
    this->str = NULL;
}

void assign_s(string_t *this, const string_t *str)
{
    if (str == NULL)
        return;
    if (this->str)
        free(this->str);
    this->str = malloc(strlen(str->str) + 1);
    if (this->str == NULL)
        return;
    strcpy(this->str, str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (s == NULL)
        return;
    if (this->str)
        free(this->str);
    this->str = malloc(strlen(s) + 1);
    if (this->str == NULL)
        return;
    strcpy(this->str, s);
}

void append_s(string_t *this, const string_t *ap)
{
    if (ap == NULL)
        return;
    if (this->str == NULL) {
        this->str = malloc(strlen(ap->str) + 1);
        if (this->str == NULL)
            return;
        strcpy(this->str, ap->str);
        return;
    }
    size_t size = strlen(this->str) + strlen(ap->str) + 1;
    char *tmp = malloc(size);
    if (tmp == NULL)
        return;
    strcpy(tmp, this->str);
    strcat(tmp, ap->str);
    free(this->str);
    this->str = tmp;
}
