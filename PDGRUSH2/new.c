/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 01
*/

#include "new.h"
#include <stdarg.h>

Object *new(const Class *class, ...)
{
    va_list ap;
    Object *obj;

    va_start(ap, class);
    obj = va_new(class, &ap);
    va_end(ap);
    return obj;
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *obj;

    if (class == NULL)
        raise("Class is null");
    obj = malloc(class->__size__);
    if (obj == NULL)
        raise("Out of memory");
    memcpy(obj, class, class->__size__);
    if (((Class *) obj)->__ctor__ != NULL)
        ((Class *) obj)->__ctor__(obj, ap);
    return (obj);
}

void delete(Object *ptr)
{
    if (ptr == NULL)
        raise("Object is null");
    if (((Class *) ptr)->__dtor__ != NULL)
        ((Class *) ptr)->__dtor__(ptr);
    free(ptr);
}
