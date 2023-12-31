/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include "vertex.h"
#include <stdio.h>
#include "new.h"

typedef struct {
    Class base;
    int x, y, z;
} VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    (void) this;
}

static char *Vertex_str(VertexClass *this)
{
    char *str = malloc(sizeof(char) * 666);

    snprintf(str, 666, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return (str);
}

static VertexClass *Vertex_add(
    const VertexClass *this, const VertexClass *other)
{
    return (new (
        Vertex, this->x + other->x, this->y + other->y, this->z + other->z));
}

static VertexClass *Vertex_sub(
    const VertexClass *this, const VertexClass *other)
{
    return (new (
        Vertex, this->x - other->x, this->y - other->y, this->z - other->z));
}

// Create additional functions here

static const VertexClass _description = {
    {/* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t) &Vertex_ctor,
        .__dtor__ = (dtor_t) &Vertex_dtor,
        .__str__ = (to_string_t) &Vertex_str,
        .__add__ = (binary_operator_t) &Vertex_add,
        .__sub__ = (binary_operator_t) &Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL},
    .x = 0, .y = 0, .z = 0};

const Class *Vertex = (const Class *) &_description;
