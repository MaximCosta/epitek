/*
** EPITECH PROJECT, 2021
** Test
** File description:
** For test functions
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "my.h"

Test(concat_params, concatenate_parameters)
{
    int argc = 3;
    char **argv;

    argv = (char**) malloc(sizeof(char*) * argc);
    for (int i = 0; i < argc; i++)
        argv[i] = (char*) malloc(sizeof(char) * 4);
    argv[0] = "toto";
    argv[1] = "titi";
    argv[2] = "tata";
    cr_assert_str_eq(concat_params(argc, argv), "toto\ntiti\ntata");
}
