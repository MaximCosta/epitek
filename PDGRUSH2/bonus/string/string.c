/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 05
*/

#include "int.h"
#include <stdarg.h>
#include <stdlib.h>
#include "../../new.h"
#include "../../raise.h"
#include "stringcontainer.h"
#include "string.h"

typedef struct {
    StringContainer base;
    size_t _size;
    char *_string;
} StringClass;

static void String_ctor(StringClass *this, va_list *args)
{
    if (!this)
        raise("StringClass is NULL");
    this->_string = strdup(va_arg(*args, char *));
    if (!this->_string)
        raise("StringClass is NULL");
    this->_size = strlen(this->_string);
}

static void String_dtor(StringClass *this)
{
    if (!this)
        raise("StringClass is NULL");
    free(this->_string);
}

static size_t String_len(StringClass *this)
{
    return strlen(this->_string);
}

static Object *String_getitem(StringClass *this, ...)
{
    return this->_string;
}

static void String_setitem(StringClass *this, ...)
{
    va_list args;
    va_start(args, this);
    if (this->_string)
        free(this->_string);
    this->_string = strdup(va_arg(args, char *));
    va_end(args);
}

static Object *String_append(StringClass *this, ...)
{
    va_list args;
    va_start(args, this);
    StringClass *va_str = va_arg(args, StringClass *);
    char *new_str = calloc(strlen(this->_string) + strlen(va_str->_string) + 1, sizeof(char));
    if (!new_str)
        raise("StringClass is NULL");
    strcat(new_str, this->_string);
    strcat(new_str, va_str->_string);
    va_end(args);
    return new(String, new_str);
}

static void String_print(StringClass *this)
{
    printf("%s", this->_string);
}

static char *String_str(StringClass *this)
{
    return this->_string;
}

static StringClass *String_add(StringClass *this, StringClass *other)
{
    char *new_string = malloc(sizeof(char) * (this->_size + other->_size + 1));

    if (!new_string)
        raise("StringClass is NULL");
    strcpy(new_string, this->_string);
    strcat(new_string, other->_string);
    return new(String, new_string);
}

static StringClass *String_mul(StringClass *this, IntClass *other)
{
    char *new_string = calloc(this->_size * other->i + 1, sizeof(char));

    if (!new_string)
        raise("StringClass is NULL");
    for (int i = 0; i < other->i; i++)
        strcat(new_string, this->_string);

    return new(String, new_string);
}

static const StringClass _descr = {
    {
        /* Container struct */
        {
            /* Class struct */
            .__size__ = sizeof(StringClass),
            .__name__ = "String",
            .__ctor__ = (ctor_t) &String_ctor,
            .__dtor__ = (dtor_t) &String_dtor,
            .__str__ = (to_string_t) &String_str,
            .__add__ = (binary_operator_t) &String_add,
            .__sub__ = NULL,
            .__mul__ = (binary_operator_t) &String_mul,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t) &String_len,
        .__getitem__ = (getitem_t) &String_getitem,
        .__setitem__ = (setitem_t) &String_setitem,
        .__append__ = (append_t) &String_append,
        .__print__ = (print_t) &String_print,
    },
    ._size = 0, ._string = NULL};

const Class *String = (const Class *) &_descr;
