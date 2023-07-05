/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 05
*/

#pragma once

#include "../../object.h"
#include "../../raise.h"

typedef struct Container_s StringContainer;

typedef size_t (*len_t)(StringContainer *this);
typedef Object *(*getitem_t)(StringContainer *this, ...);
typedef void (*setitem_t)(StringContainer *this, ...);
typedef Object *(*append_t)(StringContainer *this, ...);
typedef void (*print_t)(StringContainer *this);

struct Container_s {
    Class base;
    len_t __len__;
    getitem_t __getitem__;
    setitem_t __setitem__;
    append_t __append__;
    print_t __print__;
};

#define len(c)          ((StringContainer *) c)->__len__(c)
#define getitem(c, ...) ((StringContainer *) c)->__getitem__(c, __VA_ARGS__)
#define setitem(c, ...) ((StringContainer *) c)->__setitem__(c, __VA_ARGS__)
#define append(c, ...)  ((StringContainer *) c)->__append__(c, __VA_ARGS__)
#define print(c)        ((StringContainer *) c)->__print__(c)
#define empty(c)        (len(c) == 0)
