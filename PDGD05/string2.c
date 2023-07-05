/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD05-maxim.costa [WSL: Ubuntu]
** File description:
** string2
*/

#include "string.h"

int compare_c(const string_t *this, const char *str)
{
    return strcmp(this->str, str);
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t len = strlen(this->str);
    if (pos >= len)
        return 0;
    if (pos + n > len)
        n = len - pos;
    strncpy(s, this->str + pos, n);
    return n;
}
