/*
** EPITECH PROJECT, 2022
** solo
** File description:
** C-x C-c
*/

#ifndef SOLO_H_
    #define SOLO_H_
    #include <stdlib.h>
    #include <unistd.h>
    #define DOWN(x) ((65 <= x && x <= 90) ? x + 32 : x )
    #define spaces(c) (c == ' ' || c == '\t')
    #define space(c) (spaces(c) || c == '\0')
#endif
