/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include "char.h"
#include <stdarg.h>
#include <stdio.h>
#include "new.h"

typedef struct {
    Class base;
    char i;
} CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->i = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    (void) this;
}

static CharClass *Char_add(const CharClass *this, const CharClass *other)
{
    return (new (Char, this->i + other->i));
}

static CharClass *Char_sub(const CharClass *this, const CharClass *other)
{
    return (new (Char, this->i - other->i));
}

static CharClass *Char_mul(const CharClass *this, const CharClass *other)
{
    return (new (Char, this->i * other->i));
}

static CharClass *Char_div(const CharClass *this, const CharClass *other)
{
    if (other->i == 0)
        raise("Division by zero");
    return (new (Char, this->i / other->i));
}

static bool Char_eq(const CharClass *this, const CharClass *other)
{
    return this->i == other->i;
}

static bool Char_gt(const CharClass *this, const CharClass *other)
{
    return this->i > other->i;
}

static bool Char_lt(const CharClass *this, const CharClass *other)
{
    return this->i < other->i;
}

static char *Char_str(CharClass *this)
{
    char *str = malloc(sizeof(char) * 666);

    snprintf(str, 666, "<Char (%c)>", this->i);
    return (str);
}

static const CharClass _description = {
    {
        /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t) &Char_ctor,
        .__dtor__ = (dtor_t) &Char_dtor,
        .__str__ = (to_string_t) &Char_str /* BONUS */,
        .__add__ = (binary_operator_t) &Char_add,
        .__sub__ = (binary_operator_t) &Char_sub,
        .__mul__ = (binary_operator_t) &Char_mul,
        .__div__ = (binary_operator_t) &Char_div,
        .__eq__ = (binary_comparator_t) &Char_eq,
        .__gt__ = (binary_comparator_t) &Char_gt,
        .__lt__ = (binary_comparator_t) &Char_lt,
    },
    .i = 0};

const Class *Char = (const Class *) &_description;
