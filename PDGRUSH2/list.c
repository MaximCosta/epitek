/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 05
*/

#include "list.h"
#include <stdarg.h>
#include <stdlib.h>
#include "new.h"
#include "raise.h"

typedef struct list_s ListClass;

typedef struct linked_list_s {
    Object *_value;
    struct linked_list_s *_next;
} LinkedList;

// ListClass
struct list_s {
    Container base;
    Class *_type;
    size_t _size;
    LinkedList *_list;
};

typedef struct {
    Iterator base;
    ListClass *_list;
    LinkedList *_current;
} ListIteratorClass;

static void ListIterator_ctor(ListIteratorClass *this, va_list *args)
{
    this->_list = va_arg(*args, ListClass *);
    this->_current = va_arg(*args, LinkedList *);
}

static bool ListIterator_eq(
    ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_current == other->_current);
}

static void ListIterator_next(ListIteratorClass *this)
{
    if (!this->_current)
        raise("Out of range");
    this->_current = this->_current->_next;
}

static Object *ListIterator_getval(ListIteratorClass *this)
{
    if (!this->_current)
        return NULL;
    if (!this->_current->_value)
        raise("Out of range");
    return (this->_current->_value);
}

static void ListIterator_setval(ListIteratorClass *this, ...)
{
    va_list ap;

    va_start(ap, this);
    if (!this->_current->_value)
        raise("Out of range");
    delete(this->_current->_value);
    this->_current->_value = va_new(this->_list->_type, &ap);
    va_end(ap);
}

static const ListIteratorClass ListIteratorDescr = {
    {
        /* Iterator struct */
        {
            /* Class struct */
            .__size__ = sizeof(ListIteratorClass),
            .__name__ = "ListIterator",
            .__ctor__ = (ctor_t) &ListIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t) &ListIterator_eq,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__incr__ = (incr_t) &ListIterator_next,
        .__getval__ = (getval_t) &ListIterator_getval,
        .__setval__ = (setval_t) &ListIterator_setval,
    },
    ._list = NULL, ._current = NULL};

static const Class *ListIterator = (const Class *) &ListIteratorDescr;

static void List_addelematback(ListClass *class, LinkedList **this, Object *value)
{
    LinkedList *tmp = *this;
    LinkedList *new = calloc(1, sizeof(LinkedList));

    if (!new)
        raise("Out of memory");
    new->_value = value;
    new->_next = NULL;
    class->_size += 1;
    if (!*this) {
        *this = new;
        return;
    }
    while (tmp->_next)
        tmp= tmp->_next;
    tmp->_next = new;
}

static void List_ctor(ListClass *this, va_list *args)
{
    Object *value;
    Object *tmp;
    size_t tmp_size = va_arg(*args, size_t);

    this->_size = 0;
    this->_type = va_arg(*args, Class *);
    value = va_new(this->_type, args);
    this->_list = NULL;
    for (size_t i = 0; i < tmp_size; i++) {
        tmp = malloc(this->_type->__size__);
        if (!tmp)
            raise("Out of memory");
        memcpy(tmp, value, this->_type->__size__);
        List_addelematback(this, &this->_list, tmp);
    }
    delete (value);
}

static void List_dtor(ListClass *this)
{
    LinkedList *tmp;

    while (this->_list) {
        tmp = this->_list;
        this->_list = this->_list->_next;
        delete (tmp->_value);
        free(tmp);
    }
}

static size_t List_len(ListClass *this)
{
    return (this->_size);
}

static Iterator *List_begin(ListClass *this)
{
    return (new (ListIterator, this, this->_list));
}

static Iterator *List_end(ListClass *this)
{
    LinkedList *tmp = this->_list;

    while (tmp->_next)
        tmp = tmp->_next;
    return (new (ListIterator, this, tmp));
}

static Object *List_getitem(ListClass *this, ...)
{
    va_list ap;
    size_t index;
    LinkedList *tmp = this->_list;

    va_start(ap, this);
    index = va_arg(ap, size_t);
    va_end(ap);
    if (index >= this->_size)
        raise("Out of range");
    for (size_t i = 0; i < index; i++)
        tmp = tmp->_next;
    return (tmp->_value);
}

static void List_setitem(ListClass *this, ...)
{
    LinkedList *tmp = this->_list;
    va_list ap;
    size_t position;
    Object *value;

    va_start(ap, this);
    position = va_arg(ap, size_t);
    value = va_new(this->_type, &ap);
    if (position >= this->_size)
        raise("Out of range");
    for (size_t i = 0; i < position; i++)
        tmp = tmp->_next;
    delete (tmp->_value);
    tmp->_value = value;
    va_end(ap);
}

static const ListClass _descr = {
    {
        /* Container struct */
        {
            /* Class struct */
            .__size__ = sizeof(ListClass),
            .__name__ = "List",
            .__ctor__ = (ctor_t) &List_ctor,
            .__dtor__ = (dtor_t) &List_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t) &List_len,
        .__begin__ = (iter_t) &List_begin,
        .__end__ = (iter_t) &List_end,
        .__getitem__ = (getitem_t) &List_getitem,
        .__setitem__ = (setitem_t) &List_setitem,
    },
    ._type = NULL, ._size = 0, ._list = NULL};

const Class *List = (const Class *) &_descr;
