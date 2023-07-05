/*
** EPITECH PROJECT, 2021
** template
** File description:
** template
*/

#include "../include/op.h"

op_t op_tab[] = {{"live", false, 1, {T_DIR}, 1, 10, "alive", 32},
    {"ld", true, 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 32},
    {"st", true, 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 32},
    {"add", true, 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 32},
    {"sub", true, 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 32},
    {"and", true, 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6,
        6, "et (and  r1, r2, r3   r1&r2 -> r3", 32},
    {"or", true, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7,
        6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 32},
    {"xor", true, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8,
        6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 32},
    {"zjmp", false, 1, {T_DIR}, 9, 20, "jump if zero", 16},
    {"ldi", true, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
        "load index", 16},
    {"sti", true, 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
        "store index", 16},
    {"fork", false, 1, {T_DIR}, 12, 800, "fork", 16},
    {"lld", true, 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 32},
    {"lldi", true, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
        "long load index", 16},
    {"lfork", false, 1, {T_DIR}, 15, 1000, "long fork", 16},
    {"aff", true, 1, {T_REG}, 16, 2, "aff", 32}, {0, 0, 0, {0}, 0, 0, 0, 0}};
