/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD05-maxim.costa [WSL: Ubuntu]
** File description:
** string1
*/

#include "string.h"

void append_c(string_t *this, const char *ap)
{
    if (ap == NULL)
        return;
    if (this->str == NULL) {
        this->str = malloc(strlen(ap) + 1);
        if (this->str == NULL)
            return;
        strcpy(this->str, ap);
        return;
    }
    size_t size = strlen(this->str) + strlen(ap) + 1;
    char *tmp = malloc(size);
    if (tmp == NULL)
        return;
    strcpy(tmp, this->str);
    strcat(tmp, ap);
    free(this->str);
    this->str = tmp;
}

char func_at(const string_t *this, size_t pos)
{
    if (this->str == NULL)
        return (-1);
    if (pos >= strlen(this->str))
        return (-1);
    return (this->str[pos]);
}

void clear(string_t *this)
{
    if (this->str)
        free(this->str);
    this->str = NULL;
}

size_t length(const string_t *this)
{
    if (this->str == NULL)
        return (0);
    return (strlen(this->str));
}

int compare_s(const string_t *this, const string_t *str)
{
    return strcmp(this->str, str->str);
}
