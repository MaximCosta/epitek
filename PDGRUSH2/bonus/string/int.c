/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include "int.h"
#include <stdarg.h>
#include <stdio.h>
#include "../../new.h"

static void Int_ctor(IntClass *this, va_list *args)
{
    this->i = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    (void) this;
}

static IntClass *Int_add(const IntClass *this, const IntClass *other)
{
    return (new (Int, this->i + other->i));
}

static IntClass *Int_sub(const IntClass *this, const IntClass *other)
{
    return (new (Int, this->i - other->i));
}

static IntClass *Int_mul(const IntClass *this, const IntClass *other)
{
    return (new (Int, this->i * other->i));
}

static IntClass *Int_div(const IntClass *this, const IntClass *other)
{
    if (other->i == 0)
        raise("Division by zero");
    return (new (Int, this->i / other->i));
}

static bool Int_eq(const IntClass *this, const IntClass *other)
{
    return this->i == other->i;
}

static bool Int_gt(const IntClass *this, const IntClass *other)
{
    return this->i > other->i;
}

static bool Int_lt(const IntClass *this, const IntClass *other)
{
    return this->i < other->i;
}

static char *Int_str(IntClass *this)
{
    char *str = malloc(sizeof(char) * 666);

    snprintf(str, 666, "<Int (%d)>", this->i);
    return (str);
}

static const IntClass _description = {
    {
        /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t) &Int_ctor,
        .__dtor__ = (dtor_t) &Int_dtor,
        .__str__ = (to_string_t) &Int_str /* BONUS */,
        .__add__ = (binary_operator_t) &Int_add,
        .__sub__ = (binary_operator_t) &Int_sub,
        .__mul__ = (binary_operator_t) &Int_mul,
        .__div__ = (binary_operator_t) &Int_div,
        .__eq__ = (binary_comparator_t) &Int_eq,
        .__gt__ = (binary_comparator_t) &Int_gt,
        .__lt__ = (binary_comparator_t) &Int_lt,
    },
    .i = 0};

const Class *Int = (const Class *) &_description;
