/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD05-maxim.costa [WSL: Ubuntu]
** File description:
** string
*/

#ifndef STRING_H_
    #define STRING_H_
    #include <stdlib.h>
    #include <string.h>
    typedef struct string string_t;
    struct string {
        char *str;
        void (*assign_s)(string_t *, const string_t *);
        void (*assign_c)(string_t *, const char *);
        void (*append_s)(string_t *, const string_t *);
        void (*append_c)(string_t *, const char *);
        char (*at)(const string_t *, size_t);
        void (*clear)(string_t *);
        size_t (*length)(const string_t *);
        int (*compare_s)(const string_t *, const string_t *);
        int (*compare_c)(const string_t *, const char *);
        size_t (*copy)(const string_t *, char *, size_t, size_t);
    };
    void string_init(string_t *this, const char *s);
    void string_destroy(string_t *this);
    void assign_s(string_t *this, const string_t *str);
    void assign_c(string_t *this, const char *s);
    void append_s(string_t *this, const string_t *ap);
    void append_c(string_t *this, const char *ap);
    char func_at(const string_t *this, size_t pos);
    void clear(string_t *this);
    size_t length(const string_t *this);
    int compare_s(const string_t *this, const string_t *str);
    int compare_c(const string_t *this, const char *str);
    size_t copy(const string_t *this, char *s, size_t n, size_t pos);

#endif /* !STRING_H_ */
