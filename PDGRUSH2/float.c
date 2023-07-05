/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include "float.h"
#include <stdarg.h>
#include <stdio.h>
#include "new.h"

typedef struct {
    Class base;
    float i;
} FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->i = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    (void) this;
}

static FloatClass *Float_add(const FloatClass *this, const FloatClass *other)
{
    return (new (Float, this->i + other->i));
}

static FloatClass *Float_sub(const FloatClass *this, const FloatClass *other)
{
    return (new (Float, this->i - other->i));
}

static FloatClass *Float_mul(const FloatClass *this, const FloatClass *other)
{
    return (new (Float, this->i * other->i));
}

static FloatClass *Float_div(const FloatClass *this, const FloatClass *other)
{
    if (other->i == 0.0)
        raise("Division by zero");
    return (new (Float, this->i / other->i));
}

static bool Float_eq(const FloatClass *this, const FloatClass *other)
{
    return this->i == other->i;
}

static bool Float_gt(const FloatClass *this, const FloatClass *other)
{
    return this->i > other->i;
}

static bool Float_lt(const FloatClass *this, const FloatClass *other)
{
    return this->i < other->i;
}

static char *Float_str(FloatClass *this)
{
    char *str = malloc(sizeof(char) * 666);

    snprintf(str, 666, "<Float (%f)>", this->i);
    return (str);
}

static const FloatClass _description = {
    {
        /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t) &Float_ctor,
        .__dtor__ = (dtor_t) &Float_dtor,
        .__str__ = (to_string_t) &Float_str /* BONUS */,
        .__add__ = (binary_operator_t) &Float_add,
        .__sub__ = (binary_operator_t) &Float_sub,
        .__mul__ = (binary_operator_t) &Float_mul,
        .__div__ = (binary_operator_t) &Float_div,
        .__eq__ = (binary_comparator_t) &Float_eq,
        .__gt__ = (binary_comparator_t) &Float_gt,
        .__lt__ = (binary_comparator_t) &Float_lt,
    },
    .i = 0};

const Class *Float = (const Class *) &_description;
