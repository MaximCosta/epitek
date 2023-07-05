/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD04am-maxim.costa [WSL: Ubuntu]
** File description:
** print
*/

#ifndef PRINT_H_
    #define PRINT_H_
    #pragma once
    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>
    typedef enum action_e {
        PRINT_NORMAL,
        PRINT_REVERSE,
        PRINT_UPPER,
        PRINT_42,

        PRINT_COUNT
    }   action_t;


#endif /* !PRINT_H_ */
